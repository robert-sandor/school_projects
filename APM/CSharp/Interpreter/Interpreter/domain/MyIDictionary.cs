namespace Interpreter.domain
{
    public interface MyIDictionary
    {
        bool IsEmpty();
        void Add(string key, object value);
        object LookUp(string key);
        string ToString();
    }
}