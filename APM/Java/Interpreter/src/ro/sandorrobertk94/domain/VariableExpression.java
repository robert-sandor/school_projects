package ro.sandorrobertk94.domain;

/**
 * Created by Robert on 10/15/2015.
 */
public class VariableExpression extends Expression {
    String variableID;

    public VariableExpression(String variableID) {
        this.variableID = variableID;
    }

    public VariableExpression() {
        variableID = null;
    }

    public String getVariableID() {
        return variableID;
    }

    public void setVariableID(String variableID) {
        this.variableID = variableID;
    }

    @Override
    public String toString() {
        return this.variableID;
    }

    @Override
    public Integer eval(MyIDictionary symbolTable) {
        try {
            Object o = symbolTable.lookUp(variableID);
            if (o instanceof Integer) {
                return (Integer) o;
            } else {
                throw new Exception();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}
