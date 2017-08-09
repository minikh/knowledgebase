/**
 * User: admin
 * Date: 08.07.13
 * Time: 21:39
 */
public interface ISubject {

    public void registerObserver(IObserver observer);
    public void removeObserver(IObserver observer);
    public void notifyObserver();
}
