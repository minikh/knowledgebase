/**
 * User: Миних Владимир
 * Date: 09.07.13
 * Time: 10:04
 */
public interface Subject {

    public void addObserver(Observer o);
    public void removeObserver(Observer o);
    public void notifyObserver();
}
