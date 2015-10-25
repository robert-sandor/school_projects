namespace Interpreter.domain
{
    public class PrintStatement : IStatement
    {
        private Expression _exp;

        public PrintStatement()
        {
            _exp = null;
        }

        public PrintStatement(Expression exp)
        {
            _exp = exp;
        }

        public Expression Exp
        {
            get { return _exp; }
            set { _exp = value; }
        }

        public override string ToString()
        {
            return "print ( " + _exp.ToString() + " )";
        }
    }
}