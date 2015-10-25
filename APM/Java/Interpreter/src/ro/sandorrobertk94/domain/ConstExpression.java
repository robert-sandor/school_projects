package ro.sandorrobertk94.domain;

/**
 * Created by Robert on 10/13/2015.
 */
public class ConstExpression extends Expression {
    int number;

    public ConstExpression() {
        this.number = 0;
    }

    public ConstExpression(int number) {
        this.number = number;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    @Override
    public String toString() {
        return Integer.toString(this.number);
    }

    @Override
    public Integer eval(MyIDictionary symbolTable) {
        return this.number;
    }
}
