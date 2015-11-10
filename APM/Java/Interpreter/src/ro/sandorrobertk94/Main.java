package ro.sandorrobertk94;

import ro.sandorrobertk94.controller.Controller;
import ro.sandorrobertk94.domain.ProgramState;
import ro.sandorrobertk94.domain.adts.MyLibDictionary;
import ro.sandorrobertk94.domain.adts.MyLibList;
import ro.sandorrobertk94.domain.adts.MyLibStack;
import ro.sandorrobertk94.domain.expressions.ConstExpression;
import ro.sandorrobertk94.domain.expressions.VariableExpression;
import ro.sandorrobertk94.domain.statements.AssignmentStatement;
import ro.sandorrobertk94.domain.statements.CompoundStatement;
import ro.sandorrobertk94.domain.statements.IStatement;
import ro.sandorrobertk94.domain.statements.PrintStatement;
import ro.sandorrobertk94.domain.statements.SwitchStatement;
import ro.sandorrobertk94.repository.Repository;

public class Main {

    public static void main(String[] args) {
        IStatement statement = new CompoundStatement(
                new AssignmentStatement("v", new ConstExpression(1)),
                new SwitchStatement(
                        new VariableExpression("v"),
                        new ConstExpression(1),
                        new ConstExpression(2),
                        new PrintStatement(new ConstExpression(1)),
                        new PrintStatement(new ConstExpression(2)),
                        new PrintStatement(new ConstExpression(0))
                )
        );

        MyLibStack<IStatement> execStack = new MyLibStack<IStatement>();
        MyLibDictionary<String, Integer> symTable = new MyLibDictionary<String, Integer>();
        MyLibList<String> output = new MyLibList<String>();

        execStack.push(statement);
        ProgramState prog = new ProgramState(execStack, symTable, output, statement);
        Repository repo = new Repository();
        repo.add(prog);

        Controller con = new Controller(repo);
//        ConsoleUI ui = new ConsoleUI(con);
        String o = con.allStep();
//        System.out.println(o);
//        ui.run();
    }
}
