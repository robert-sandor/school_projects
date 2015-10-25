package ro.sandorrobertk94.domain;

/**
 * Created by robert on 10/25/15.
 */
public class MyList implements MyIList {
    private static final int CAPACITY = 50;
    private int size;
    private Object[] objList;

    public MyList() {
        size = 0;
        objList = new Object[CAPACITY];
    }

    @Override
    public void add(Object obj) {
        objList[size] = obj;
        size++;
    }

    @Override
    public Object get(int pos) {
        if (pos < size) {
            return objList[pos];
        }
        return null;
    }

    @Override
    public int getSize() {
        return size;
    }

    @Override
    public String toString() {
        String out = "[ size =" + size + "\n";
        for (int i = 0; i < size; i++) {
            out += "\t" + objList[i].toString() + "\n";
        }
        out += "];";
        return out;
    }
}
