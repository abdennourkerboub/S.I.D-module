/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Abdennour_Kerboub;

/**
 *
 * @author hp
 */
import java.io.*;
import java.net.*;

public class Client {

    static final int port = 6666;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        Socket socket = new Socket("localhost", port);
        System.out.println("SOCKET = " + socket);

        BufferedReader plec = new BufferedReader(
                new InputStreamReader(socket.getInputStream())
        );

        PrintWriter pred = new PrintWriter(
                new BufferedWriter(
                        new OutputStreamWriter(socket.getOutputStream())),
                true);

        String str = "HI";

        while (true) {

            for (int i = 1; i < 10; i++) {

                System.out.println(plec.readLine());
                pred.println(str + " " + i);

            }
            System.out.println(plec.readLine() + " Awsome");

        }

    }
}


