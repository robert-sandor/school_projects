package ro.sandorrobertk94.domain;

import ro.sandorrobertk94.domain.adts.MyIDictionary;
import ro.sandorrobertk94.domain.adts.MyIList;
import ro.sandorrobertk94.domain.adts.MyIStack;
import ro.sandorrobertk94.domain.statements.IStatement;

/**
 * Created by robert on 10/25/15.
 */
public class ProgramState {
    private MyIStack<IStatement> executionStack;
    private MyIDictionary<String, Integer> symbolTable;
    private MyIList<String> out;
    private IStatement originalProgram;

    public ProgramState(MyIStack<IStatement> executionStack, MyIDictionary<String, Integer> symbolTable,
                        MyIList<String> out, IStatement program) {
        this.executionStack = executionStack;
        this.symbolTable = symbolTable;
        this.out = out;
        this.originalProgram = program;
    }

    public MyIStack<IStatement> getExecutionStack() {
        return executionStack;
    }

    public void setExecutionStack(MyIStack<IStatement> executionStack) {
        this.executionStack = executionStack;
    }

    public MyIDictionary<String, Integer> getSymbolTable() {
        return symbolTable;
    }

    public void setSymbolTable(MyIDictionary<String, Integer> symbolTable) {
        this.symbolTable = symbolTable;
    }

    public MyIList<String> getOut() {
        return out;
    }

    public void setOut(MyIList<String> out) {
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
