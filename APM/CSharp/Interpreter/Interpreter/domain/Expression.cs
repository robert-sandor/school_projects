namespace Interpreter.domain
{
    public abstract class Expression
    {
        public abstract int Eval(MyIDictionary symbolTable);
        public abstract override string ToString();
    }
}