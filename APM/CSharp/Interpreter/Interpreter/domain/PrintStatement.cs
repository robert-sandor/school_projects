namespace Interpreter.domain
{
    public class PrintStatement : IStatement
    {
        public PrintStatement()
        {
            Exp = null;
        }

        public PrintStatement(Expression exp)
        {
            Exp = exp;
        }

        public Expression Exp { get; set; }

        public override string ToString()
        {
            return "print ( " + Exp + " )";
        }
    }
}