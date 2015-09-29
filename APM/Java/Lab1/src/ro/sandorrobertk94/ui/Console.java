package ro.sandorrobertk94.ui;

/**
 * Created by robert on 9/29/15.
 */
public class Console {
    public void run (String[] args) {
        int[] array = null;
        array = ReadData(args);

    }

    private int[] ReadData(String[] args) {
        int[] array = new int[args.length];
        for (int i = 0; i < args.length; ++i) {
            try {
                array[i] = Integer.parseInt(args[i]);
            }
            catch (NumberFormatException) {
                array[i] = 0;
            }
        }
    }
}
