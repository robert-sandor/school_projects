using System;
using Interpreter.controller;
using Interpreter.domain;

namespace Interpreter.view
{
    public class ConsoleUI
    {
        private readonly Controller _controller;

        public ConsoleUI(Controller controller)
        {
            _controller = controller;
        }

        public void Run()
        {
            while (true)
            {
                PrintMainMenu();

                var option = Convert.ToInt32(Console.ReadLine());

                switch (option)
                {
                    case 1:
                    {
                        var state = InputProgram();
                        if (state == null)
                        {
                            return;
                        }

                        _controller.Repo.Add(state);
                        Console.WriteLine();
                        Console.WriteLine(state.OriginalProgram.ToString());
                        Console.WriteLine();
                        break;
                    }
                    case 2:
                    {
                        OneStep();
                        break;
                    }
                    case 3:
                    {
                        AllStep();
                        break;
                    }
                    case 4:
                    {
                        return;
                    }
                    default:
                    {
                        Console.WriteLine("!!! Invalid option !!!");
                        break;
                    }
                }
            }
        }

        private ProgramState InputProgram()
        {
            var initialStack = new MyStack();

            var initialStatement = InputStatement();
            if (initialStatement == null)
            {
                return null;
            }

            initialStack.Push(initialStatement);
            return new ProgramState(initialStack, new MyDictionary(), new MyList(), initialStatement);
        }

        private IStatement InputStatement()
        {
            PrintStatementMenu();
            IStatement statement;

            var option = Convert.ToInt32(Console.ReadLine());

            switch (option)
            {
                case 1:
                {
                    statement = new CompoundStatement();

                    Console.WriteLine("Input first statement : ");
                    var st1 = InputStatement();
                    Console.WriteLine("Input second statement : ");
                    var st2 = InputStatement();

                    if (st1 == null || st2 == null)
                    {
                        return null;
                    }

                    ((CompoundStatement) statement).FirstStatement = st1;
                    ((CompoundStatement) statement).SecondStatement = st2;
                    break;
                }
                case 2:
                {
                    statement = new AssignmentStatement();

                    Console.WriteLine("Variable id :");
                    var varid = Console.ReadLine();

                    Console.WriteLine("Input exception");
                    var exp = InputExpression();
                    if (exp == null)
                    {
                        return null;
                    }

                    ((AssignmentStatement) statement).VariableId = varid;
                    ((AssignmentStatement) statement).Exp = exp;
                    break;
                }
                case 3:
                {
                    statement = new IfStatement();
                    Console.WriteLine("Input expression : ");
                    var exp = InputExpression();
                    Console.WriteLine("Input then statement : ");
                    var st1 = InputStatement();
                    Console.WriteLine("Input else statement : ");
                    var st2 = InputStatement();

                    if (exp == null || st1 == null || st2 == null)
                    {
                        return null;
                    }

                    ((IfStatement) statement).Exp = exp;
                    ((IfStatement) statement).ThenStatement = st1;
                    ((IfStatement) statement).ElseStatement = st2;
                    break;
                }
                case 4:
                {
                    statement = new PrintStatement();

                    Console.WriteLine("Input expression : ");
                    var exp = InputExpression();
                    if (exp == null)
                    {
                        return null;
                    }
                    ((PrintStatement) statement).Exp = exp;
                    break;
                }
                default:
                {
                    Console.WriteLine("Invalid option!");
                    return null;
                }
            }
            return statement;
        }

        private Expression InputExpression()
        {
            PrintExpressionMenu();

            var option = Convert.ToInt32(Console.ReadLine());
            Expression exp;
            switch (option)
            {
                case 1:
                {
                    Console.Write("Input an integer : ");
                    var number = Convert.ToInt32(Console.ReadLine());
                    exp = new ConstantExpression(number);
                    break;
                }
                case 2:
                {
                    exp = new ArithmeticExpression();

                    Console.WriteLine("Input expression : ");
                    var exp1 = InputExpression();

                    Console.Write("Input operator ( + , - , * , / ) : ");
                    var sop = Console.ReadLine();
                    switch (sop)
                    {
                        case "+":
                        {
                            ((ArithmeticExpression) exp).Op = ArithmeticExpression.Operator.Add;
                            break;
                        }
                        case "-":
                        {
                            ((ArithmeticExpression) exp).Op = ArithmeticExpression.Operator.Sub;
                            break;
                        }
                        case "*":
                        {
                            ((ArithmeticExpression) exp).Op = ArithmeticExpression.Operator.Mul;
                            break;
                        }
                        case "/":
                        {
                            ((ArithmeticExpression) exp).Op = ArithmeticExpression.Operator.Div;
                            break;
                        }
                        default:
                        {
                            Console.WriteLine("!!! Bad Operator !!!");
                            return null;
                        }
                    }

                    Console.WriteLine("Input expression : ");
                    var exp2 = InputExpression();

                    if (exp1 == null || exp2 == null)
                    {
                        return null;
                    }
                    ((ArithmeticExpression) exp).Exp1 = exp;
                    ((ArithmeticExpression) exp).Exp2 = exp2;
                    break;
                }
                case 3:
                {
                    Console.Write("Variable id : ");
                    var varid = Console.ReadLine();
                    exp = new VariableExpression(varid);
                    break;
                }
                default:
                {
                    Console.WriteLine("!!! Invalid option !!!");
                    return null;
                }
            }
            return exp;
        }

        private void OneStep()
        {
            var output = _controller.OneStep(_controller.Repo.GetCurentProgramState(0));
            Console.WriteLine(output);
        }

        private void AllStep()
        {
            var output = _controller.AllStep();
            Console.WriteLine(output);
        }

        private void PrintMainMenu()
        {
            Console.WriteLine("--- Main Menu ---");
            Console.WriteLine("1. Input program");
            Console.WriteLine("2. One Step");
            Console.WriteLine("3. All Step");
            Console.WriteLine("4. Exit");
        }

        private void PrintStatementMenu()
        {
            Console.WriteLine("1. Compound Statement");
            Console.WriteLine("2. Assignment");
            Console.WriteLine("3. If Statement");
            Console.WriteLine("4. Print Statement");
        }

        private void PrintExpressionMenu()
        {
            Console.WriteLine("1. Constant Expression");
            Console.WriteLine("2. Arithmetic Expression");
            Console.WriteLine("3. Variable Expression");
        }
    }
}