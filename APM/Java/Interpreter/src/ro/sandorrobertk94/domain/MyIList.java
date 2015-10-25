package ro.sandorrobertk94.domain;

/**
 * Created by robert on 10/25/15.
 */
public interface MyIList {
    void add(Object obj);
    Object get(int pos);
    int getSize();
    String toString();
}
