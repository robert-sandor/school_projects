namespace Interpreter.domain
{
    public class ConstantExpression : Expression
    {
        public ConstantExpression()
        {
            Number = 0;
        }

        public ConstantExpression(int number)
        {
            Number = number;
        }

        public int Number { get; set; }

        public override int Eval(MyIDictionary symbolTable)
        {
            return Number;
        }

        public override string ToString()
        {
            return Number.ToString();
        }
    }
}