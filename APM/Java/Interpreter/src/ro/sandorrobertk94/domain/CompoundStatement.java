package ro.sandorrobertk94.domain;

/**
 * Created by Robert on 10/11/2015.
 */
public class CompoundStatement implements IStatement {
    private IStatement firstStatement;
    private IStatement secondStatement;

    public CompoundStatement() {
        this.firstStatement = null;
        this.secondStatement = null;
    }

    public CompoundStatement(IStatement statement1, IStatement statement2) {
        this.firstStatement = statement1;
        this.secondStatement = statement2;
    }

    public IStatement getFirstStatement() {
        return firstStatement;
    }

    public void setFirstStatement(IStatement firstStatement) {
        this.firstStatement = firstStatement;
    }

    public IStatement getSecondStatement() {
        return secondStatement;
    }

    public void setSecondStatement(IStatement secondStatement) {
        this.secondStatement = secondStatement;
    }

    @Override
    public String toString() {
        return "( " + this.firstStatement.toString() + " ; " + this.secondStatement.toString() + " )";
    }
}
