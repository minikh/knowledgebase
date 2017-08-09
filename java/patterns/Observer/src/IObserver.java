/**
 * User: admin
 * Date: 08.07.13
 * Time: 21:36
 * Наблюдатель
 */
public interface IObserver {

    public void update(Double temp, Double pleasure, Double vlazhn);

    public void register();
    public void remove();

}
