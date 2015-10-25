namespace Interpreter.domain
{
    public interface MyIStack
    {
        bool IsEmpty();
        object Top();
        void Push(object obj);
        object Pop();
        string ToString();
    }
}