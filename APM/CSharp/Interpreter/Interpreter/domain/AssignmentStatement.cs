namespace Interpreter.domain
{
    public class AssignmentStatement : IStatement
    {
        private string _variableId;
        private Expression _exp;

        public AssignmentStatement()
        {
            _variableId = null;
            _exp = null;
        }

        public AssignmentStatement(string variableId, Expression exp)
        {
            _variableId = variableId;
            _exp = exp;
        }

        public string VariableId
        {
            get { return _variableId; }
            set { _variableId = value; }
        }

        public Expression Exp
        {
            get { return _exp; }
            set { _exp = value; }
        }

        public override string ToString()
        {
            return _variableId + " = " + _exp.ToString();
        }
    }
}