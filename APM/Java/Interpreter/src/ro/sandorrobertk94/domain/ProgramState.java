package ro.sandorrobertk94.domain;

/**
 * Created by robert on 10/25/15.
 */
public class ProgramState {
    private MyIStack executionStack;
    private MyIDictionary symbolTable;
    private MyIList out;
    private IStatement originalProgram;

    public ProgramState(MyIStack executionStack, MyIDictionary symbolTable, MyIList out, IStatement program) {
        this.executionStack = executionStack;
        this.symbolTable = symbolTable;
        this.out = out;
        this.originalProgram = program;
    }

    public MyIStack getExecutionStack() {
        return executionStack;
    }

    public void setExecutionStack(MyIStack executionStack) {
        this.executionStack = executionStack;
    }

    public MyIDictionary getSymbolTable() {
        return symbolTable;
    }

    public void setSymbolTable(MyIDictionary symbolTable) {
        this.symbolTable = symbolTable;
    }

    public MyIList getOut() {
        return out;
    }

    public void setOut(MyIList out) {
        this.out = out;
    }

    public IStatement getOriginalProgram() {
        return originalProgram;
    }

    public void setOriginalProgram(IStatement originalProgram) {
        this.originalProgram = originalProgram;
    }

    @Override
    public String toString() {
        return "PROGRAM STATE => {{{\n execStack : " +
                executionStack.toString() + "\n symbolTable : " +
                symbolTable.toString() + "\n output : " +
                out.toString() + "\n}}}\n";
    }
}
