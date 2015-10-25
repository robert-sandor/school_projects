namespace Interpreter.domain
{
    public class CompoundStatement : IStatement
    {
        public CompoundStatement()
        {
            FirstStatement = null;
            SecondStatement = null;
        }

        public CompoundStatement(IStatement firstStatement, IStatement secondStatement)
        {
            FirstStatement = firstStatement;
            SecondStatement = secondStatement;
        }

        public IStatement FirstStatement { get; set; }

        public IStatement SecondStatement { get; set; }

        public override string ToString()
        {
            return "( " + FirstStatement.ToString() + " ; " + SecondStatement.ToString() + " )";
        }
    }
}