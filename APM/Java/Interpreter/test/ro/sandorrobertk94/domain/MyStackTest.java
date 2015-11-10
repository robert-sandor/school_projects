//package ro.sandorrobertk94.domain;
//
//import junit.framework.TestCase;
//
///**
// * Created by Robert on 10/26/2015.
// */
//public class MyStackTest extends TestCase {
//    MyStack stack;
//
//    public void setUp() throws Exception {
//        super.setUp();
//        stack = new MyStack();
//    }
//
//    public void tearDown() throws Exception {
//
//    }
//
//    public void testIsEmpty() throws Exception {
//        assertTrue(stack.isEmpty());
//        stack.push("a");
//        assertFalse(stack.isEmpty());
//    }
//
//    public void testTop() throws Exception {
//        stack.push("a");
//        assertEquals(stack.top(), "a");
//    }
//
//    public void testPush() throws Exception {
//        stack.push("a");
//        assertEquals(stack.pop(), "a");
//    }
//
//    public void testPop() throws Exception {
//        stack.push("a");
//        assertEquals(stack.pop(), "a");
//    }
//
//    public void testToString() throws Exception {
//        stack.push("a");
//        assertEquals(stack.toString(), "( \n\ta\n);");
//    }
//}