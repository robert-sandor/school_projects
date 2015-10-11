package ro.sandorrobertk94.domain;

/**
 * Created by Robert on 10/11/2015.
 */
public class AssignmentStatement implements IStatement {
    private String variableID;
    private Expression exp;

    public AssignmentStatement() {
        this.variableID = null;
        this.exp = null;
    }

    public AssignmentStatement(String variableID, Expression exp) {
        this.variableID = variableID;
        this.exp = exp;
    }

    public String getVariableID() {
        return variableID;
    }

    public void setVariableID(String variableID) {
        this.variableID = variableID;
    }

    public Expression getExp() {
        return exp;
    }

    public void setExp(Expression exp) {
        this.exp = exp;
    }

    @Override
    public String toString() {
        return variableID + " = " + exp.toString();
    }
}
