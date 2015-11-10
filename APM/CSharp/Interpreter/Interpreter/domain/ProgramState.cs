using Interpreter.domain.adts;
using Interpreter.domain.statements;

namespace Interpreter.domain
{
    public class ProgramState
    {
        public ProgramState(MyIStack<IStatement> executionStack, MyIDictionary<string, int> symbolTable,
            MyIList<string> output,
            IStatement originalProgram)
        {
            ExecutionStack = executionStack;
            SymbolTable = symbolTable;
            Output = output;
            OriginalProgram = originalProgram;
        }

        public MyIStack<IStatement> ExecutionStack { get; set; }

        public MyIDictionary<string, int> SymbolTable { get; set; }

        public MyIList<string> Output { get; set; }

        public IStatement OriginalProgram { get; set; }

        public override string ToString()
        {
            return "PROGRAM STATE => {{{\n execStack : " +
                   ExecutionStack.ToString() + "\n symbolTable : " +
                   SymbolTable.ToString() + "\n output : " +
                   Output.ToString() + "\n}}}\n";
        }
    }
}