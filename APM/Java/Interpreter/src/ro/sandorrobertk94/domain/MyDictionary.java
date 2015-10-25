package ro.sandorrobertk94.domain;

import java.util.Arrays;
import java.util.Objects;

/**
 * Created by robert on 10/25/15.
 */
public class MyDictionary implements MyIDictionary {
    private static final int CAPACITY = 50;
    private int size;
    private String[] keys;
    private Object[] values;

    public MyDictionary() {
        size = 0;
        keys = new String[CAPACITY];
        values = new Object[CAPACITY];
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public void add(String key, Object value) {
        int i;
        for (i = 0; i < size; i++) {
            if (Objects.equals(key, keys[i])) {
                break;
            }
        }

        // if we found the key
        if (i < size) {
            values[i] = value;
        } else {
            keys[size] = key;
            values[size] = value;
            size++;
        }
    }

    @Override
    public Object lookUp(String key) throws Exception {
        int i;
        for (i = 0; i < size; i++) {
            if (Objects.equals(key, keys[i])) {
                break;
            }
        }

        // if we found the key
        if (i < size) {
            return values[i];
        } else {
            throw new Exception("Key not found");
        }
    }

    @Override
    public String toString() {
        String out = "{ size = " + size + "\n";
        for (int i = 0; i < size; i++) {
            out += keys[i] + " => " + values[i].toString() + "\n";
        }
        out += "};";
        return out;
    }
}
