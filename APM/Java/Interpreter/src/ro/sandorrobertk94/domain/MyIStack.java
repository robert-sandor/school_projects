package ro.sandorrobertk94.domain;

import java.util.EmptyStackException;

/**
 * Created by robert on 10/25/15.
 */
public interface MyIStack {
    int size();
    boolean isEmpty();
    Object top() throws EmptyStackException;
    void push(Object o);
    Object pop() throws EmptyStackException;
    String toString();
}
