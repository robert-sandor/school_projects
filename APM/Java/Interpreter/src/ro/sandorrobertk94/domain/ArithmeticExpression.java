package ro.sandorrobertk94.domain;

/**
 * Created by Robert on 10/13/2015.
 */
public class ArithmeticExpression extends Expression {
    public enum Operator {
        ADD, SUB, MULT, DIV, NONE
    }

    private Expression exp1;
    private Expression exp2;
    private Operator op;

    public ArithmeticExpression(Expression exp1, Expression exp2, Operator op) {
        this.exp1 = exp1;
        this.exp2 = exp2;
        this.op = op;
    }

    public ArithmeticExpression() {
        this.exp1 = null;
        this.exp2 = null;
        this.op = Operator.NONE;
    }

    public Expression getExp1() {
        return exp1;
    }

    public void setExp1(Expression exp1) {
        this.exp1 = exp1;
    }

    public Expression getExp2() {
        return exp2;
    }

    public void setExp2(Expression exp2) {
        this.exp2 = exp2;
    }

    public Operator getOp() {
        return op;
    }

    public void setOp(Operator op) {
        this.op = op;
    }

    @Override
    public String toString() {
        String sop = "";
        switch (this.op) {
            case ADD: {
                sop = "+";
                break;
            }
            case SUB: {
                sop = "-";
                break;
            }
            case MULT: {
                sop = "*";
                break;
            }
            case DIV: {
                sop = "/";
                break;
            }
        }
        return exp1.toString() + sop + exp2.toString();
    }

    @Override
    public Integer eval(MyIDictionary symbolTable) {
        int result = 0;
        switch (this.op) {
            case ADD: {
                result = exp1.eval(symbolTable) + exp2.eval(symbolTable);
                break;
            }
            case SUB: {
                result = exp1.eval(symbolTable) - exp2.eval(symbolTable);
                break;
            }
            case MULT: {
                result = exp1.eval(symbolTable) * exp2.eval(symbolTable);
                break;
            }
            case DIV: {
                result = exp1.eval(symbolTable) / exp2.eval(symbolTable);
                break;
            }
        }
        return result;
    }
}
