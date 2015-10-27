using Interpreter.controller;
using Interpreter.repository;
using Interpreter.view;

namespace Interpreter
{
    internal class Program
    {
        private static void Main(string[] args)
        {
//            IStatement statement = new CompoundStatement(
//                new AssignmentStatement(
//                    "v",
//                    new ArithmeticExpression(
//                        new ConstantExpression(2),
//                        new ConstantExpression(3),
//                        ArithmeticExpression.Operator.Add)),
//                new PrintStatement(
//                    new VariableExpression("v")));
//
//            var execStack = new MyStack();
//            var symbolTable = new MyDictionary();
//            var output = new MyList();
//
//            execStack.Push(statement);
//            var prog = new ProgramState(execStack, symbolTable, output, statement);
            var repo = new Repository();
//            repo.Add(prog);

            var con = new Controller(repo);
//            con.AllStep();\
            var cli = new ConsoleUI(con);
            cli.Run();
        }
    }
}