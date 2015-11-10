package ro.sandorrobertk94.view;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import ro.sandorrobertk94.controller.Controller;
import ro.sandorrobertk94.domain.ProgramState;
import ro.sandorrobertk94.domain.adts.MyDictionary;
import ro.sandorrobertk94.domain.adts.MyList;
import ro.sandorrobertk94.domain.adts.MyStack;
import ro.sandorrobertk94.domain.expressions.ArithmeticExpression;
import ro.sandorrobertk94.domain.expressions.ConstExpression;
import ro.sandorrobertk94.domain.expressions.Expression;
import ro.sandorrobertk94.domain.expressions.VariableExpression;
import ro.sandorrobertk94.domain.statements.AssignmentStatement;
import ro.sandorrobertk94.domain.statements.CompoundStatement;
import ro.sandorrobertk94.domain.statements.IStatement;
import ro.sandorrobertk94.domain.statements.IfStatement;
import ro.sandorrobertk94.domain.statements.PrintStatement;
import ro.sandorrobertk94.domain.statements.WhileStatement;

/**
 * Created by Robert on 10/26/2015.
 */
public class ConsoleUI {
    private Controller controller;

    public ConsoleUI(Controller controller) {
        this.controller = controller;
    }

    public void run() {
        while (true) {
            printMainMenu();

            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int option = 0;
            try {
                option = Integer.parseInt(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }

            switch (option) {
                case 1: {
                    ProgramState state = inputProgram();
                    if (state == null) {
                        return;
                    }
                    controller.getRepo().add(state);
                    System.out.println();
                    System.out.println(state.getOriginalProgram().toString());
                    System.out.println();
                    break;
                }
                case 2: {
                    oneStep();
                    break;
                }
                case 3: {
                    allStep();
                    break;
                }
                case 4: {
                    return;
                }
                default: {
                    System.out.println("!! Invalid Option !!");
                }
            }
        }
    }

    private ProgramState inputProgram() {
        IStatement initialStatement;
        MyStack initialStack = new MyStack();

        initialStatement = inputStatement();
        if (initialStatement == null) {
            return null;
        }

        initialStack.push(initialStatement);

        return new ProgramState(
                initialStack,
                new MyDictionary(),
                new MyList(),
                initialStatement
        );
    }

    private IStatement inputStatement() {
        printStatementMenu();
        IStatement statement;

        // read option
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int option = 0;
        try {
            option = Integer.parseInt(br.readLine());
        } catch (IOException e) {
            e.printStackTrace();
        }

        switch (option) {
            case 1: {
                statement = new CompoundStatement();

                System.out.println("Input first statement : ");
                IStatement st1 = inputStatement();
                System.out.println("Input second statement : ");
                IStatement st2 = inputStatement();

                if (st1 == null || st2 == null) {
                    return null;
                }

                ((CompoundStatement) statement).setFirstStatement(st1);
                ((CompoundStatement) statement).setSecondStatement(st2);
                break;
            }
            case 2: {
                statement = new AssignmentStatement();

                System.out.print("Variable id : ");
                String variableid = null;
                try {
                    variableid = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }

                System.out.println("Input expression : ");
                Expression exp = inputExpression();
                if (exp == null) {
                    return null;
                }

                ((AssignmentStatement) statement).setVariableID(variableid);
                ((AssignmentStatement) statement).setExp(exp);
                break;
            }
            case 3: {
                statement = new IfStatement();

                System.out.println("Input expression : ");
                Expression exp = inputExpression();
                System.out.println("Input first statement : ");
                IStatement st1 = inputStatement();
                System.out.println("Input second statement : ");
                IStatement st2 = inputStatement();

                if (exp == null || st1 == null || st2 == null) {
                    return null;
                }

                ((IfStatement) statement).setExp(exp);
                ((IfStatement) statement).setThenStatement(st1);
                ((IfStatement) statement).setElseStatement(st2);
                break;
            }
            case 4: {
                statement = new PrintStatement();
                System.out.println("Input expression : ");
                Expression exp = inputExpression();
                if (exp == null) {
                    return null;
                }
                ((PrintStatement) statement).setExp(exp);
                break;
            }
            case 5: {
                statement = new WhileStatement();
                System.out.println("Input expression : ");
                Expression exp = inputExpression();
                System.out.println("Input statement : ");
                IStatement st = inputStatement();
                if (exp == null || st == null) {
                    return null;
                }
                ((WhileStatement) statement).setExp(exp);
                ((WhileStatement) statement).setStatement(st);
            }
            default: {
                System.out.println("!! Invalid Option !!");
                return null;
            }
        }

        return statement;
    }

    private Expression inputExpression() {
        printExpressionMenu();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int option = 0;
        try {
            option = Integer.parseInt(br.readLine());
        } catch (IOException e) {
            e.printStackTrace();
        }

        Expression exp;
        switch (option) {
            case 1: {
                System.out.print("Input an integer : ");
                int number = 0;
                try {
                    number = Integer.parseInt(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }

                exp = new ConstExpression(number);
                break;
            }
            case 2: {
                exp = new ArithmeticExpression();

                System.out.println("Input expression : ");
                Expression exp1 = inputExpression();

                System.out.print("Input operator ( + , - , * , / ) : ");
                String sop = null;
                try {
                    sop = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }

                if (sop != null) {
                    switch (sop) {
                        case "+": {
                            ((ArithmeticExpression) exp).setOp(ArithmeticExpression.Operator.ADD);
                            break;
                        }
                        case "-": {
                            ((ArithmeticExpression) exp).setOp(ArithmeticExpression.Operator.SUB);
                            break;
                        }
                        case "*": {
                            ((ArithmeticExpression) exp).setOp(ArithmeticExpression.Operator.MULT);
                            break;
                        }
                        case "/": {
                            ((ArithmeticExpression) exp).setOp(ArithmeticExpression.Operator.DIV);
                            break;
                        }
                        default: {
                            System.out.println("!! Bad Operator !!");
                            return null;
                        }
                    }
                }

                System.out.println("Input expression : ");
                Expression exp2 = inputExpression();

                if (exp1 == null || exp2 == null) {
                    return null;
                }

                ((ArithmeticExpression) exp).setExp1(exp1);
                ((ArithmeticExpression) exp).setExp2(exp2);
                break;
            }
            case 3: {
                exp = new VariableExpression();

                System.out.print("Variable id :");
                String variableid = null;
                try {
                    variableid = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }

                ((VariableExpression) exp).setVariableID(variableid);
                break;
            }
            default: {
                System.out.println("!! Invalid Option !!");
                return null;
            }
        }
        return exp;
    }

    private void oneStep() {
        String output = controller.oneStep(controller.getRepo().getCurrentProgram(0));
        System.out.println(output);
    }

    private void allStep() {
        String output = controller.allStep();
        System.out.println(output);
    }

    private void printMainMenu() {
        System.out.println("--- Main Menu ---");
        System.out.println("1. Input program");
        System.out.println("2. One Step");
        System.out.println("3. All Step");
        System.out.println("4. Exit");
    }

    private void printStatementMenu() {
        System.out.println("1. Compound Statement");
        System.out.println("2. Assignment");
        System.out.println("3. If Statement");
        System.out.println("4. Print Statement");
        System.out.println("5. While Statement");
    }

    private void printExpressionMenu() {
        System.out.println("1. Constant Expression");
        System.out.println("2. Arithmetic Expression");
        System.out.println("3. Variable Expression");
    }
}
