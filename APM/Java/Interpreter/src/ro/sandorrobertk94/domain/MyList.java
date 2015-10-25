package ro.sandorrobertk94.domain;

import java.util.Arrays;

/**
 * Created by robert on 10/25/15.
 */
public class MyList implements MyIList {
    private static final int CAPACITY = 50;
    private int size;
    private Object[] objList;

    @Override
    public void add() {
        size = 0;
        objList = new Object[CAPACITY];
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
            out += objList[i].toString() + "\n";
        }
        out += "];";
        return out;
    }
}
