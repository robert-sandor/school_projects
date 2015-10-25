package ro.sandorrobertk94.domain;

import java.util.EmptyStackException;

/**
 * Created by robert on 10/25/15.
 */
public class MyStack implements MyIStack {
    private static final int CAPACITY = 50;
    private int top;
    private Object[] stackArray;

    public MyStack() {
        top = 0;
        stackArray = new Object[CAPACITY];
    }

    @Override
    public int size() {
        return top;
    }

    @Override
    public boolean isEmpty() {
        return top == 0;
    }

    @Override
    public Object top() throws EmptyStackException {
        if (isEmpty()) {
            throw new EmptyStackException();
        }

        return stackArray[top - 1];
    }

    @Override
    public void push(Object o) {
        stackArray[top] = o;
        top++;
    }

    @Override
    public Object pop() throws EmptyStackException {
        if (isEmpty()) {
            throw new EmptyStackException();
        }

        top--;
        Object o = stackArray[top];
        stackArray[top] = null;
        return o;
    }

    @Override
    public String toString() {
        String out = "( \n";
        for (int i = top-1; i >= 0; i--) {
            out += "\t" + stackArray[i].toString() + "\n";
        }
        out += ");";
        return out;
    }
}
