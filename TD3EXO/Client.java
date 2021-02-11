import java.rmi.*;
import java.net.*;
import java.io.*;
import java.util.*;

/*
Abdennour Kerboub
 */
public class Client {

    public static void main(String args[]) {
        String host = "localhost";
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the 1st parameter");
        int a = sc.nextInt();
        System.out.println("Enter the 2nd Paramater");
        int b = sc.nextInt();
        try {
            Addrem remobj = (Addrem) Naming.lookup("rmi://" + host + "/Addrem");
            System.out.println(remobj.addNum(a, b));
        } catch (RemoteException re) {
            re.printStackTrace();
        } catch (NotBoundException nbe) {
            nbe.printStackTrace();
        } catch (MalformedURLException mfe) {
            mfe.printStackTrace();
        }
    }
}
