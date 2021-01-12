/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Abdennour_Kerboub;

import java.io.*;
import java.net.*;

/**
 *
 * @author hp
 */
public class Server extends Thread {

    int port = 6666;
    int nbClient;

    @Override
    public void run() {
        try {
            ServerSocket s = new ServerSocket(port);
            while (true) {
                Socket soc = s.accept();
                ++nbClient;
                new Client(soc, nbClient).start();

            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    class Client extends Thread {

        private Socket socket;
        private int nclient;

        public Client(Socket socket, int nbC) {

            this.socket = socket;
            this.nclient = nbC;
        }

        @Override
        public void run() {
            try {

                BufferedReader plec = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                PrintWriter pred = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);

                String IP = socket.getRemoteSocketAddress().toString();
                System.out.println("Connection du Client : " + nclient + " avec l'IP " + IP);
                pred.println("Hello , Client  " + nclient);

                while (true) {
                    String request;

                    while ((request = plec.readLine()) != null) {

                        System.out.println("Client " + nclient + " says: " + request);
                        String response = "Message Received number :  ";
                        pred.println(response);

                    }
                }

            } catch (IOException e) {
                e.printStackTrace();
            }

        }
    }

    public static void main(String[] args) throws Exception {
        new Server().start();
        System.out.println("Server Start...");

    }

}
