namespace Interpreter.domain
{
    public class ProgramState
    {
        public ProgramState(MyIStack executionStack, MyIDictionary symbolTable, MyIList output,
            IStatement originalProgram)
        {
            ExecutionStack = executionStack;
            SymbolTable = symbolTable;
            Output = output;
            OriginalProgram = originalProgram;
        }

        public MyIStack ExecutionStack { get; set; }

        public MyIDictionary SymbolTable { get; set; }

        public MyIList Output { get; set; }

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