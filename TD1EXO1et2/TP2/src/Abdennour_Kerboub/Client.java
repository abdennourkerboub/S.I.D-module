/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Abdennour_Kerboub;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

/**
 *
 * @author hp
 */
public class Client {

    public static DatagramSocket s;

    public static void main(String[] args) throws Exception {

        s = new DatagramSocket(null);
        s.connect(InetAddress.getByName("localhost"), 9999);
        String message = "connetion test .....";
        byte[] buff = message.getBytes();
        s.send(new DatagramPacket(buff, buff.length));

    }

}
