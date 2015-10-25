package ro.sandorrobertk94;

import ro.sandorrobertk94.controller.Controller;
import ro.sandorrobertk94.domain.*;
import ro.sandorrobertk94.repository.Repository;

public class Main {

    public static void main(String[] args) {
        IStatement statement = new CompoundStatement(
                new AssignmentStatement(
                        "v",
                        new ArithmeticExpression(
                                new ConstExpression(2),
                                new ConstExpression(3),
                                ArithmeticExpression.Operator.MULT
                        )),
                new PrintStatement(
                        new VariableExpression("v")
                ));

        MyStack execStack = new MyStack();
        MyDictionary symTable = new MyDictionary();
        MyList output = new MyList();

        execStack.push(statement);
        ProgramState prog = new ProgramState(execStack, symTable, output, statement);
        Repository repo = new Repository();
        repo.add(prog);

        Controller con = new Controller(repo);
        con.allStep();
    }
}
