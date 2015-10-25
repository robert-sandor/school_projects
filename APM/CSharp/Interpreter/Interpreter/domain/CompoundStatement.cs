namespace Interpreter.domain
{
    public class CompoundStatement : IStatement
    {
        private IStatement firstStatement;
        private IStatement secondStatement;

        public CompoundStatement()
        {
            this.firstStatement = null;
            this.secondStatement = null;
        }

        public CompoundStatement(IStatement firstStatement, IStatement secondStatement)
        {
            this.firstStatement = firstStatement;
            this.secondStatement = secondStatement;
        }

        public IStatement FirstStatement
        {
            get { return firstStatement; }
            set { firstStatement = value; }
        }

        public IStatement SecondStatement
        {
            get { return secondStatement; }
            set { secondStatement = value; }
        }

        public override string ToString()
        {
            return "( " + this.firstStatement.ToString() + " ; " + this.secondStatement.ToString() + " )";
        }
    }
}