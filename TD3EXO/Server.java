import java.rmi.*;
import java.net.*;

/*
Abdennour Kerboub
 */
public class Server {

    public static void main(String args[]) {
        try {
            implementation locobj = new implementation();
            Naming.rebind("rmi:///Addrem", locobj);
        } catch (RemoteException re) {
            re.printStackTrace();
        } catch (MalformedURLException mfe) {
            mfe.printStackTrace();
        }
    }
}