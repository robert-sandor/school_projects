using System;

namespace Interpreter.domain
{
    public class VariableExpression : Expression
    {
        public VariableExpression()
        {
            VariableId = null;
        }

        public VariableExpression(string variableId)
        {
            VariableId = variableId;
        }

        public string VariableId { get; set; }

        public override int Eval(MyIDictionary symbolTable)
        {
            var o = symbolTable.LookUp(VariableId);
            if (o is int)
            {
                return (int) o;
            }
            throw new Exception();
        }

        public override string ToString()
        {
            return VariableId;
        }
    }
}