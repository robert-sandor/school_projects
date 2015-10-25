namespace Interpreter.domain
{
    public interface MyIList
    {
        void Add(object obj);
        object Get(int pos);
        int getSize();
        string ToString();
    }
}