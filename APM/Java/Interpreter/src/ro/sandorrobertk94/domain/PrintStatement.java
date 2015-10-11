package ro.sandorrobertk94.domain;

/**
 * Created by Robert on 10/11/2015.
 */
public class PrintStatement implements IStatement {
    private Expression exp;

    public PrintStatement() {
        this.exp = null;
    }

    public PrintStatement(Expression exp) {
        this.exp = exp;
    }

    public Expression getExp() {
        return exp;
    }

    public void setExp(Expression exp) {
        this.exp = exp;
    }

    @Override
    public String toString() {
        return "print ( " + exp.toString() + " )";
    }
}
