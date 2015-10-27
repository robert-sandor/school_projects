package ro.sandorrobertk94.controller;

import ro.sandorrobertk94.domain.*;
import ro.sandorrobertk94.repository.IRepository;

/**
 * Created by Robert on 10/25/2015.
 */
public class Controller {
    public IRepository getRepo() {
        return repo;
    }

    public void setRepo(IRepository repo) {
        this.repo = repo;
    }

    private IRepository repo;

    public Controller(IRepository repo) {
        this.repo = repo;
    }

    public String oneStep(ProgramState state) {
        MyIStack stack = state.getExecutionStack();
        String output = "";

        if (stack.isEmpty()) {
            return output;
        }

        IStatement currentStatement = (IStatement) stack.pop();
        if (currentStatement instanceof CompoundStatement) {
            CompoundStatement s = (CompoundStatement) currentStatement;
            stack.push(s.getSecondStatement());
            stack.push(s.getFirstStatement());
        }

        if (currentStatement instanceof AssignmentStatement) {
            AssignmentStatement s = (AssignmentStatement) currentStatement;
            Expression exp = s.getExp();
            String id = s.getVariableID();
            MyIDictionary symbolTable = state.getSymbolTable();
            int val = exp.eval(symbolTable);
            symbolTable.add(id, val);
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
        }

        if (currentStatement instanceof PrintStatement) {
            PrintStatement s = (PrintStatement) currentStatement;
            Expression exp = s.getExp();
            MyIDictionary symbolTable = state.getSymbolTable();
            int val = exp.eval(symbolTable);
            state.getOut().add(Integer.toString(val));
        }
        return output;
    }

    public String allStep() {
        ProgramState state = repo.getCurrentProgram(0);
        String output = "";
        output += state.toString() + "\n";
        while (!state.getExecutionStack().isEmpty()) {
            oneStep(state);
            output += state.toString() + "\n";
        }
        return output;
    }
}
