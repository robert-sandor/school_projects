package ro.sandorrobertk94.controller;

import ro.sandorrobertk94.domain.ProgramState;
import ro.sandorrobertk94.domain.adts.MyIDictionary;
import ro.sandorrobertk94.domain.adts.MyIStack;
import ro.sandorrobertk94.domain.expressions.ArithmeticExpression;
import ro.sandorrobertk94.domain.expressions.Expression;
import ro.sandorrobertk94.domain.statements.AssignmentStatement;
import ro.sandorrobertk94.domain.statements.CompoundStatement;
import ro.sandorrobertk94.domain.statements.IStatement;
import ro.sandorrobertk94.domain.statements.IfStatement;
import ro.sandorrobertk94.domain.statements.IfThenStatement;
import ro.sandorrobertk94.domain.statements.PrintStatement;
import ro.sandorrobertk94.domain.statements.SkipStatement;
import ro.sandorrobertk94.domain.statements.SwitchStatement;
import ro.sandorrobertk94.domain.statements.WhileStatement;
import ro.sandorrobertk94.repository.IRepository;

/**
 * Created by Robert on 10/25/2015.
 */
public class Controller {
    private IRepository repo;

    public Controller(IRepository repo) {
        this.repo = repo;
    }

    public IRepository getRepo() {
        return repo;
    }

    public void setRepo(IRepository repo) {
        this.repo = repo;
    }

    public String oneStep(ProgramState state) {
        MyIStack<IStatement> stack = state.getExecutionStack();

        if (stack.isEmpty()) {
            return state.toString();
        }

        IStatement currentStatement = stack.pop();
        if (currentStatement instanceof CompoundStatement) {
            CompoundStatement s = (CompoundStatement) currentStatement;
            stack.push(s.getSecondStatement());
            stack.push(s.getFirstStatement());
        }

        if (currentStatement instanceof AssignmentStatement) {
            AssignmentStatement s = (AssignmentStatement) currentStatement;
            Expression exp = s.getExp();
            String id = s.getVariableID();
            MyIDictionary<String, Integer> symbolTable = state.getSymbolTable();
            int val = exp.eval(symbolTable);
            symbolTable.add(id, val);
        }

        if (currentStatement instanceof IfStatement) {
            IfStatement s = (IfStatement) currentStatement;
            Expression exp = s.getExp();
            MyIDictionary<String, Integer> symbolTable = state.getSymbolTable();
            int val = exp.eval(symbolTable);
            if (val != 0) {
                stack.push(s.getThenStatement());
            } else {
                stack.push(s.getElseStatement());
            }
        }

        if (currentStatement instanceof IfThenStatement) {
            IfThenStatement s = (IfThenStatement) currentStatement;
            stack.push(new IfStatement(s.getExp(), s.getThenStatement(), new SkipStatement()));
        }

        if (currentStatement instanceof PrintStatement) {
            PrintStatement s = (PrintStatement) currentStatement;
            Expression exp = s.getExp();
            MyIDictionary<String, Integer> symbolTable = state.getSymbolTable();
            int val = exp.eval(symbolTable);
            state.getOut().add(Integer.toString(val));
        }

        if (currentStatement instanceof WhileStatement) {
            WhileStatement s = (WhileStatement) currentStatement;
            Expression exp = s.getExp();
            MyIDictionary<String, Integer> symbolTable = state.getSymbolTable();
            int val = exp.eval(symbolTable);
            if (val != 0) {
                stack.push(s);
                stack.push(s.getStatement());
            }
        }

        if (currentStatement instanceof SwitchStatement) {
            SwitchStatement s = (SwitchStatement) currentStatement;
            stack.push(new IfStatement(
                    new ArithmeticExpression(
                            s.getVar(),
                            s.getCase2(),
                            ArithmeticExpression.Operator.SUB
                    ),
                    new IfStatement(
                            new ArithmeticExpression(
                                    s.getVar(),
                                    s.getCase1(),
                                    ArithmeticExpression.Operator.SUB
                            ),
                            s.getDefaultStatement(),
                            s.getStatement1()
                    ),
                    s.getStatement2()
            ));
        }

        System.out.println(state.toString());
        return state.toString();
    }

    public String allStep() {
        ProgramState state = repo.getCurrentProgram(0);
        String output = "";
        output += state.toString() + "\n";
        System.out.println(output);
        while (!state.getExecutionStack().isEmpty()) {
            oneStep(state);
            output += state.toString() + "\n";
        }
        return output;
    }
}
