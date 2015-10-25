using System;

namespace Interpreter.domain
{
    public class MyDictionary : MyIDictionary
    {
        private const int Capacity = 50;
        private int _size;
        private string[] _keys;
        private object[] _values;

        public MyDictionary()
        {
            _size = 0;
            _keys = new string[Capacity];
            _values = new object[Capacity];
        }


        public bool IsEmpty()
        {
            return _size == 0;
        }

        public void Add(string key, object value)
        {
            int i;
            for (i = 0; i < _size; i++)
            {
                if (key == _keys[i])
                {
                    break;
                }
            }

            if (i < _size)
            {
                _values[i] = value;
            }
            else
            {
                _keys[_size] = key;
                _values[_size] = value;
                _size++;
            }
        }

        public object LookUp(string key)
        {
            int i;
            for (i = 0; i < _size; i++)
            {
                if (key == _keys[i])
                {
                    break;
                }
            }

            if (i < _size)
            {
                return _values[i];
            }
            else
            {
                throw new Exception("Key not found!");
            }
        }

        public string ToString()
        {
            var o = "{ size = " + _size + "\n";
            for (var i = 0; i < _size; i++)
            {
                o += _keys[i] + " => " + _values[i].ToString() + "\n";
            }
            o += "};";
            return o;
        }
    }
}