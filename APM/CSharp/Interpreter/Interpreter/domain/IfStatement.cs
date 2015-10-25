using System.Runtime.CompilerServices;

namespace Interpreter.domain
{
    public class IfStatement : IStatement
    {
        private Expression _exp;
        private IStatement _thenStatement;
        private IStatement _elseStatement;

        public IfStatement()
        {
            _exp = null;
            _thenStatement = null;
            _elseStatement = null;
        }

        public IfStatement(Expression exp, IStatement thenStatement, IStatement elseStatement)
        {
            _exp = exp;
            _thenStatement = thenStatement;
            _elseStatement = elseStatement;
        }

        public Expression Exp
        {
            get { return _exp; }
            set { _exp = value; }
        }

        public IStatement ThenStatement
        {
            get { return _thenStatement; }
            set { _thenStatement = value; }
        }

        public IStatement ElseStatement
        {
            get { return _elseStatement; }
            set { _elseStatement = value; }
        }

        public override string ToString()
        {
            return "IF ( " + _exp.ToString() + " ) THEN ( " + _thenStatement.ToString() + " ) ELSE ( " + _elseStatement.ToString() + " )";
        }
    }
}