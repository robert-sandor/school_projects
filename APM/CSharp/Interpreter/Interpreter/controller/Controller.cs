using Interpreter.domain;
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
            var output = "";
            var stack = state.ExecutionStack;
            if (stack.IsEmpty())
            {
                return output;
            }

            var currentStatement = (IStatement) stack.Pop();
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

            if (currentStatement is PrintStatement)
            {
                var s = (PrintStatement) currentStatement;
                var exp = s.Exp;
                var symbolTable = state.SymbolTable;
                var val = exp.Eval(symbolTable);
                state.Output.Add(val.ToString());
            }
            return output;
        }

        public string AllStep()
        {
            var state = Repo.GetCurentProgramState(0);
            var output = state + "\n";
            while (!state.ExecutionStack.IsEmpty())
            {
                OneStep(state);
                output += state + "\n";
            }
            return output;
        }
    }
}