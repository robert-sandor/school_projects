using Interpreter.controller;
using Interpreter.domain;
using Interpreter.domain.adts;
using Interpreter.domain.expressions;
using Interpreter.domain.statements;
using Interpreter.repository;

namespace Interpreter
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            IStatement statement = new CompoundStatement(
                new AssignmentStatement("v", new ConstantExpression(1)),
                new SwitchStatement(
                    new VariableExpression("v"),
                    new ConstantExpression(1),
                    new ConstantExpression(2),
                    new PrintStatement(new ConstantExpression(1)),
                    new PrintStatement(new ConstantExpression(2)),
                    new PrintStatement(new ConstantExpression(0))
                    )
                );

            var execStack = new MyLibStack<IStatement>();
            var symbolTable = new MyLibDictionary<string, int>();
            var output = new MyLibList<string>();

            execStack.Push(statement);
            var prog = new ProgramState(execStack, symbolTable, output, statement);
            var repo = new Repository();
            repo.Add(prog);

            var con = new Controller(repo);
            var o = con.AllStep();
//            Console.WriteLine(o);
//            var cli = new ConsoleUI(con);
//            cli.Run();
        }
    }
}