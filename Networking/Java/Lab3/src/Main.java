import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Main {

    public static void main(String[] args) {

        int PORT = 12345;
        try (ServerSocket serverSocket = new ServerSocket(PORT)) {

            while (true) {
                try {
                    new ServerThread(serverSocket.accept());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class ServerThread implements Runnable {
    private Socket csocket;

    public ServerThread(Socket s) {
        this.csocket = s;

        (new Thread(this)).start();
    }

    public void run() {
        System.out.println("Connection to : " +
                csocket.getInetAddress().toString() + " : " + Integer.toString(csocket.getPort()));

        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(csocket.getInputStream()));

            String fromClient;
            while ((fromClient = in.readLine()) != null) {
                System.out.println(csocket.getInetAddress().toString() + " : " + Integer.toString(csocket.getPort())
                        + " -> " + fromClient);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}