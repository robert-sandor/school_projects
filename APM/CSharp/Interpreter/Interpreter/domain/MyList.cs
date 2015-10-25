namespace Interpreter.domain
{
    public class MyList : MyIList
    {
        private const int CAPACITY = 50;
        private readonly object[] objList;
        private int size;

        public MyList()
        {
            size = 0;
            objList = new object[CAPACITY];
        }

        public void Add(object obj)
        {
            objList[size] = obj;
            size++;
        }

        public object Get(int pos)
        {
            if (pos < size)
            {
                return objList[pos];
            }
            return null;
        }

        public int getSize()
        {
            return size;
        }

        public override string ToString()
        {
            var o = "[ size = " + size + "\n";
            for (var i = 0; i < size; i++)
            {
                o += "\t" + objList[i] + "\n";
            }
            o += "];";
            return o;
        }
    }
}