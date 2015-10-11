package ro.sandorrobertk94.domain;

/**
 * Created by Robert on 10/11/2015.
 */
public class IfStatement implements IStatement {
    private Expression exp;
    private IStatement thenStatement;
    private IStatement elseStatement;

    public IfStatement() {
        this.exp = null;
        this.thenStatement = null;
        this.elseStatement = null;
    }

    public IfStatement(Expression exp, IStatement thenStatement, IStatement elseStatement) {
        this.exp = exp;
        this.thenStatement = thenStatement;
        this.elseStatement = elseStatement;
    }

    public Expression getExp() {
        return exp;
    }

    public void setExp(Expression exp) {
        this.exp = exp;
    }

    public IStatement getThenStatement() {
        return thenStatement;
    }

    public void setThenStatement(IStatement thenStatement) {
        this.thenStatement = thenStatement;
    }

    public IStatement getElseStatement() {
        return elseStatement;
    }

    public void setElseStatement(IStatement elseStatement) {
        this.elseStatement = elseStatement;
    }

    @Override
    public String toString() {
        return "IF ( " + this.exp.toString() + " ) THEN ( " + this.thenStatement.toString() +
                " ) ELSE ( " + this.elseStatement.toString() + " )";
    }
}
