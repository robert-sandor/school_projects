using System;
using Interpreter.domain;
using Interpreter.repository;

namespace Interpreter.controller
{
    public class Controller
    {
        private readonly IRepository repo;

        public Controller(IRepository repo)
        {
            this.repo = repo;
        }

        public void OneStep(ProgramState state)
        {
            var stack = state.ExecutionStack;
            if (stack.IsEmpty())
            {
                return;
            }

            var currentStatement = (IStatement) stack.Pop();
            if (currentStatement is CompoundStatement)
            {
                var s = (CompoundStatement) currentStatement;
                stack.Push(s.SecondStatement);
                stack.Push(s.FirstStatement);
                return;
            }

            if (currentStatement is AssignmentStatement)
            {
                var s = (AssignmentStatement) currentStatement;
                var exp = s.Exp;
                var id = s.VariableId;
                var symbolTable = state.SymbolTable;
                var val = exp.Eval(symbolTable);
                symbolTable.Add(id, val);
                return;
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
                return;
            }

            if (currentStatement is PrintStatement)
            {
                var s = (PrintStatement) currentStatement;
                var exp = s.Exp;
                var symbolTable = state.SymbolTable;
                var val = exp.Eval(symbolTable);
                state.Output.Add(val.ToString());
            }
        }

        public void AllStep()
        {
            var state = repo.GetCurentProgramState(0);
            Console.WriteLine(state.ToString());
            while (!state.ExecutionStack.IsEmpty())
            {
                OneStep(state);
                Console.WriteLine(state.ToString());
            }
        }
    }
}