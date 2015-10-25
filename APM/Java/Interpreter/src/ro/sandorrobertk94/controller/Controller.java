package ro.sandorrobertk94.controller;

import ro.sandorrobertk94.domain.*;
import ro.sandorrobertk94.repository.IRepository;

/**
 * Created by Robert on 10/25/2015.
 */
public class Controller {
    private IRepository repo;

    public Controller(IRepository repo) {
        this.repo = repo;
    }

    public void oneStep(ProgramState state) {
        MyIStack stack = state.getExecutionStack();
        if (stack.isEmpty()) {
            return;
        }

        IStatement currentStatement = (IStatement) stack.pop();
        if (currentStatement instanceof CompoundStatement) {
            CompoundStatement s = (CompoundStatement) currentStatement;
            stack.push(s.getSecondStatement());
            stack.push(s.getFirstStatement());
            return;
        }

        if (currentStatement instanceof AssignmentStatement) {
            AssignmentStatement s = (AssignmentStatement) currentStatement;
            Expression exp = s.getExp();
            String id = s.getVariableID();
            MyIDictionary symbolTable = state.getSymbolTable();
            int val = exp.eval(symbolTable);
            symbolTable.add(id, val);
            return;
        }

        if (currentStatement instanceof IfStatement) {
            IfStatement s = (IfStatement) currentStatement;
            Expression exp = s.getExp();
            MyIDictionary symbolTable = state.getSymbolTable();
            int val = exp.eval(symbolTable);
            if (val != 0) {
                stack.push(s.getThenStatement());
            } else {
                stack.push(s.getElseStatement());
            }
            return;
        }

        if (currentStatement instanceof PrintStatement) {
            PrintStatement s = (PrintStatement) currentStatement;
            Expression exp = s.getExp();
            MyIDictionary symbolTable = state.getSymbolTable();
            int val = exp.eval(symbolTable);
            state.getOut().add(Integer.toString(val));
        }
    }

    public void allStep() {
        ProgramState state = repo.getCurrentProgram(0);
        System.out.println(state.toString());
        while (!state.getExecutionStack().isEmpty()) {
            oneStep(state);
            System.out.println(state.toString());
        }
    }
}
