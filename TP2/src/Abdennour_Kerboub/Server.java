/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Abdennour_Kerboub;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetSocketAddress;
import java.net.SocketTimeoutException;

/**
 *
 * @author hp
 */


public class Server {

    public static DatagramSocket s;

    public static void main(String[] args) throws Exception {
        s = new DatagramSocket(null);
        s.bind(new InetSocketAddress(9999));
        s.setSoTimeout(5000);
        byte[] buff = new byte[256];
        DatagramPacket p = new DatagramPacket(buff, 256);
        while (true) {
            try {
                s.receive(p);
                System.out.println("received ; " + new String(p.getData(), 0, p.getLength()));

            } catch (SocketTimeoutException e) {
                System.out.println("no message received for 5 seconds ..");

            }

        }

    }

}
