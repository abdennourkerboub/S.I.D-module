import java.rmi.*;

/*
Abdennour Kerboub
 */
public interface Addrem extends Remote {

    public int addNum(int a, int b) throws RemoteException;
}