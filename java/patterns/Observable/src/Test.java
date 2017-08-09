import java.util.Observable;

/**
 * User: admin
 * Date: 08.07.13
 * Time: 22:55
 */
public class Test {

    public static void main(String[] args){

        WeatherData weatherData = new WeatherData();

       CurrentDisplay currentDisplay = new CurrentDisplay(weatherData);


        weatherData.setWeather(1.0, 20.0, 50.0);
        weatherData.setWeather(2.0, 20.0, 50.0);
    }
}
