import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;

/*
Abdennour Kerboub
 */
public class implementation extends UnicastRemoteObject implements Addrem {

    public implementation() throws RemoteException {
    }

    public int addNum(int a, int b) {
        return (a + b);
    }
}