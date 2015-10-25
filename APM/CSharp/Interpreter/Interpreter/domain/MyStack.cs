namespace Interpreter.domain
{
    public class MyStack : MyIStack
    {
        private const int CAPACITY = 50;
        private readonly object[] stackArray;
        private int top;

        public MyStack()
        {
            stackArray = new object[CAPACITY];
            top = 0;
        }

        public bool IsEmpty()
        {
            return top == 0;
        }

        public object Top()
        {
            return IsEmpty() ? null : stackArray[top - 1];
        }

        public void Push(object obj)
        {
            stackArray[top] = obj;
            top++;
        }

        public object Pop()
        {
            if (IsEmpty())
            {
                return null;
            }

            var o = Top();
            top--;
            stackArray[top] = null;
            return o;
        }

        public override string ToString()
        {
            var o = "( \n";
            for (var i = top - 1; i >= 0; i--)
            {
                o += "\t" + stackArray[i] + "\n";
            }
            o += ");";
            return o;
        }
    }
}