package ro.sandorrobertk94.domain;

/**
 * Created by robert on 10/25/15.
 */
public interface MyIDictionary {
    boolean isEmpty();
    void add(String key, Object value);
    Object lookUp(String key) throws Exception;
    String toString();
}
