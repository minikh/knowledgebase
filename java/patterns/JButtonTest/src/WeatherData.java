import java.util.ArrayList;

/**
 * User: Миних Владимир
 * Date: 09.07.13
 * Time: 10:07
 */
public class WeatherData implements Subject {

    private ArrayList<Observer> observers = new ArrayList<Observer>();
    private Double t;
    private Double p;
    private Double v;

    public void newWeather(Double t, Double p, Double v){
        this.p = p;
        this.t = t;
        this.v = v;

        notifyObserver();
    }


    @Override
    public void addObserver(Observer o) {
        observers.add(o);
    }

    @Override
    public void removeObserver(Observer o) {
        int i = observers.indexOf(o);
        if (i >= 0){
            observers.remove(i);
        }
    }

    @Override
    public void notifyObserver() {
        for(Observer o: observers){
            o.update(t, p, v);
        }
    }


    public static void main(String[] args){

        WeatherData weatherData = new WeatherData();
        WidjetAll widjetAll = new WidjetAll(weatherData);
        widjetAll.register();

        weatherData.newWeather(1.0, 10.0, 20.0);
        weatherData.newWeather(2.0, 10.0, 20.0);

        widjetAll.unRegister();
        weatherData.newWeather(1.0, 10.0, 20.0);
        weatherData.newWeather(2.0, 10.0, 20.0);
    }
}
