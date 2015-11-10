using System;
using Interpreter.domain;
using Interpreter.domain.expressions;
using Interpreter.domain.statements;
using Interpreter.repository;

namespace Interpreter.controller
{
    public class Controller
    {
        public Controller(IRepository repo)
        {
            Repo = repo;
        }

        public IRepository Repo { get; }

        public string OneStep(ProgramState state)
        {
            var stack = state.ExecutionStack;
            if (stack.IsEmpty())
            {
                return state.ToString();
            }

            var currentStatement = stack.Pop();
            if (currentStatement is CompoundStatement)
            {
                var s = (CompoundStatement) currentStatement;
                stack.Push(s.SecondStatement);
                stack.Push(s.FirstStatement);
            }

            if (currentStatement is AssignmentStatement)
            {
                var s = (AssignmentStatement) currentStatement;
                var exp = s.Exp;
                var id = s.VariableId;
                var symbolTable = state.SymbolTable;
                var val = exp.Eval(symbolTable);
                symbolTable.Add(id, val);
            }

            if (currentStatement is IfStatement)
            {
                var s = (IfStatement) currentStatement;
                var exp = s.Exp;
                var symbolTable = state.SymbolTable;
                var val = exp.Eval(symbolTable);
                if (val != 0)
                {
                    stack.Push(s.ThenStatement);
                }
                else
                {
                    stack.Push(s.ElseStatement);
                }
            }

            if (currentStatement is IfThenStatement)
            {
                var s = (IfThenStatement) currentStatement;
                stack.Push(new IfStatement(
                    s.Exp, s.ThenStatement, new SkipStatement()));
            }

            if (currentStatement is PrintStatement)
            {
                var s = (PrintStatement) currentStatement;
                var exp = s.Exp;
                var symbolTable = state.SymbolTable;
                var val = exp.Eval(symbolTable);
                state.Output.Add(val.ToString());
            }

            if (currentStatement is WhileStatement)
            {
                var s = (WhileStatement) currentStatement;
                var exp = s.Exp;
                var symbolTable = state.SymbolTable;
                var val = exp.Eval(symbolTable);
                if (val != 0)
                {
                    stack.Push(s);
                    stack.Push(s.Statement);
                }
            }

            if (currentStatement is SwitchStatement)
            {
                var s = (SwitchStatement) currentStatement;
                stack.Push(
                    new IfStatement(
                        new ArithmeticExpression(
                            s.Varexp,
                            s.Case2,
                            ArithmeticExpression.Operator.Sub),
                        new IfStatement(
                            new ArithmeticExpression(
                                s.Varexp,
                                s.Case1,
                                ArithmeticExpression.Operator.Sub),
                            s.DefaultStatement,
                            s.Statement1),
                        s.Statement1
                        ));
            }

            Console.WriteLine(state.ToString());
            return state.ToString();
        }

        public string AllStep()
        {
            var state = Repo.GetCurentProgramState(0);
            var output = state + "\n";
            Console.WriteLine(state.ToString());
            while (!state.ExecutionStack.IsEmpty())
            {
                OneStep(state);
                output += state + "\n";
            }
            return output;
        }
    }
}