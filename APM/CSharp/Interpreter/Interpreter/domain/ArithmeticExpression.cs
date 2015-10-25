namespace Interpreter.domain
{
    public class ArithmeticExpression : Expression
    {
        public enum Operator
        {
            Add,
            Sub,
            Mul,
            Div,
            None
        }

        public ArithmeticExpression()
        {
            Exp1 = null;
            Exp2 = null;
            Op = Operator.None;
        }

        public ArithmeticExpression(Expression exp1, Expression exp2, Operator op)
        {
            Exp1 = exp1;
            Exp2 = exp2;
            Op = op;
        }

        public Expression Exp1 { get; set; }

        public Expression Exp2 { get; set; }

        public Operator Op { get; set; }


        public override int Eval(MyIDictionary symbolTable)
        {
            var result = 0;

            switch (Op)
            {
                case Operator.Add:
                {
                    result = Exp1.Eval(symbolTable) + Exp2.Eval(symbolTable);
                    break;
                }
                case Operator.Sub:
                {
                    result = Exp1.Eval(symbolTable) + Exp2.Eval(symbolTable);
                    break;
                }
                case Operator.Mul:
                {
                    result = Exp1.Eval(symbolTable)*Exp2.Eval(symbolTable);
                    break;
                }
                case Operator.Div:
                {
                    result = Exp1.Eval(symbolTable)/Exp2.Eval(symbolTable);
                    break;
                }
                case Operator.None:
                    break;
            }

            return result;
        }

        public override string ToString()
        {
            var sop = "";

            switch (Op)
            {
                case Operator.Add:
                {
                    sop = "+";
                    break;
                }
                case Operator.Sub:
                {
                    sop = "-";
                    break;
                }
                case Operator.Mul:
                {
                    sop = "*";
                    break;
                }
                case Operator.Div:
                {
                    sop = "/";
                    break;
                }
                case Operator.None:
                    sop = " None ";
                    break;
            }

            return Exp1 + sop + Exp2;
        }
    }
}