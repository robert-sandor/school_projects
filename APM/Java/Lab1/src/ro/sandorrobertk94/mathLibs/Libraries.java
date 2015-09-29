package ro.sandorrobertk94.mathLibs;

/**
 * Created by robert on 9/29/15.
 */
public class Libraries {

    /**
     * Checks whether a number is prime
     * @param nr - natural number
     * @return true if nr is prime, false otherwise
     */
    public static boolean isPrime(int nr) {
        if (nr < 2) {
            return false;
        }

        int i;
        for (i = 2; i * i < nr; i++) {
            if (nr % i == 0) {
                return false;
            }
        }

        return true;
    }

}
