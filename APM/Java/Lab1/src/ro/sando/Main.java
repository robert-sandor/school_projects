// 4. Determina numerele prime p1 si p2 gemene imediat superioare numarului natural nenul n dat. Doua numere prime p si q sunt gemene  daca q-p = 2.

package ro.sando;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) {
        App app = new App();
        app.run(args);
    }
}

class App {
    /**
     * Runs the app
     * @param args - arguments passed through the console
     */
    public void run(String[] args) {
        // ask for a number
        System.out.print("Enter a number : ");

        // read the line
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = null;
        try {
            input = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }

        // parse the string to an integer
        int n;
        try {
            n = Integer.parseInt(input);
        }
        catch (NumberFormatException e) {
            System.err.println("Invalid number!");
            return;
        }

        // find the primes for the condition
        int first, second;
        first = second = n + 1;
        while (true) {
            second++;
            if (isPrime(second)) {
                if (second - first == 2 && isPrime(first)) {
                    System.out.println(first + " " + second);
                    break;
                }
                else {
                    first = second;
                }
            }
        }
    }

    /**
     * Checks if a number is prime
     * @param x - the number to be checked
     * @return true / false - the number is prime / is not prime
     */
    public boolean isPrime(int x) {
        if ( x <= 1 ) {
            return false;
        }
        if ( x % 2 == 0 ) {
            return false;
        }
        for (int div = 3; div <= Math.sqrt(x); div += 2) {
            if ( x % div == 0 ) {
                return false;
            }
        }
        return true;
    }
}
