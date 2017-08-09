import java.util.Observable;
import java.util.Observer;

/**
 * User: admin
 * Date: 08.07.13
 * Time: 21:42
 * Вывод информации о погоде
 */
public class CurrentDisplay implements Observer, IDisplayElement {

    private Observable observable;
    private Double temp;
    private Double pleasure;
    private Double vlazhn;

    public CurrentDisplay(Observable observable) {
        this.observable = observable;
        this.observable.addObserver(this);
    }

    @Override
    public void update(Observable o, Object arg) {

        if (o instanceof Observable){
            WeatherData weatherData = (WeatherData)o;
            temp = weatherData.getTemp();
            pleasure = weatherData.getPleasure();
            vlazhn = weatherData.getVlazhn();
            display();
        }
    }

    @Override
    public void display() {

        System.out.println("-------CurrentDisplay--------");
        System.out.print("Температура " + temp);
        System.out.print(", давление " + pleasure);
        System.out.println(", влажность " + vlazhn);
    }



}
