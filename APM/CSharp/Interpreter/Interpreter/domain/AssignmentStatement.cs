namespace Interpreter.domain
{
    public class AssignmentStatement : IStatement
    {
        public AssignmentStatement()
        {
            VariableId = null;
            Exp = null;
        }

        public AssignmentStatement(string variableId, Expression exp)
        {
            VariableId = variableId;
            Exp = exp;
        }

        public string VariableId { get; set; }

        public Expression Exp { get; set; }

        public override string ToString()
        {
            return VariableId + " = " + Exp;
        }
    }
}