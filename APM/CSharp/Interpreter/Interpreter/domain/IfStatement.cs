namespace Interpreter.domain
{
    public class IfStatement : IStatement
    {
        public IfStatement()
        {
            Exp = null;
            ThenStatement = null;
            ElseStatement = null;
        }

        public IfStatement(Expression exp, IStatement thenStatement, IStatement elseStatement)
        {
            Exp = exp;
            ThenStatement = thenStatement;
            ElseStatement = elseStatement;
        }

        public Expression Exp { get; set; }

        public IStatement ThenStatement { get; set; }

        public IStatement ElseStatement { get; set; }

        public override string ToString()
        {
            return "IF ( " + Exp + " ) THEN ( " + ThenStatement.ToString() + " ) ELSE ( " + ElseStatement.ToString() +
                   " )";
        }
    }
}