import java.util.ArrayList;

/**
 * User: admin
 * Date: 08.07.13
 * Time: 21:48
 * Класс реализует метеостанцию
 */
public class WeatherData implements ISubject {

    private ArrayList<IObserver> observers = new ArrayList<IObserver>();
    private Double temp;
    private Double pleasure;
    private Double vlazhn;

    /**
     * Регистрируем наблюдателя
     * @param observer
     */
    @Override
    public void registerObserver(IObserver observer) {
        observers.add(observer);
    }

    /**
     * Удляем наблюдателя
     * @param observer
     */
    @Override
    public void removeObserver(IObserver observer) {
        int i = observers.indexOf(observer);
        if (i>=0){
            observers.remove(i);
        }
    }

    /**
     * Оповещаем всех зарегистрированных наблюдателей
     */
    @Override
    public void notifyObserver() {

        for (IObserver o: observers){
            o.update(temp, pleasure, vlazhn);
        }
    }

    /**
     * Получаем сведения о погоде
     * @param temp
     * @param pleasure
     * @param vlazhn
     */
    public void setWeather(Double temp, Double pleasure, Double vlazhn){
        this.temp = temp;
        this.pleasure = pleasure;
        this.vlazhn = vlazhn;

        notifyObserver();
    }
}
