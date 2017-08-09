/**
 * User: admin
 * Date: 08.07.13
 * Time: 21:54
 */
public class Test {

    public static void main(String[] args){

        //метеостанция
        WeatherData weatherData = new WeatherData();

        //виджет с текущей погодой
        CurrentDisplay currentDisplay = new CurrentDisplay(weatherData);
        //виджет с текущей температурой
        CurrentTemp currentTemp = new CurrentTemp(weatherData);


        //currentTemp.remove();
        //подписываем виджет на обновления
        currentTemp.register();

        //подписываем виджет на обновления
        currentDisplay.register();
        //меняем погоду
        weatherData.setWeather(1.0, 20.0, 100.0);
        weatherData.setWeather(2.0, 20.0, 100.0);

        //отписываем виджет от обновлений
        currentDisplay.remove();

        //меняем погоду
        weatherData.setWeather(3.0, 20.0, 100.0);
        weatherData.setWeather(4.0, 20.0, 100.0);




    }
}
