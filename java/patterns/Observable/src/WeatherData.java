import java.util.Observable;
import java.util.Observer;

/**
 * User: admin
 * Date: 08.07.13
 * Time: 22:38
 */
public class WeatherData extends Observable {

    private Double temp;
    private Double pleasure;
    private Double vlazhn;

    private void weatherChanged(){
        setChanged();
        notifyObservers();
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
        weatherChanged();
    }

    public Double getTemp() {
        return temp;
    }

    public Double getPleasure() {
        return pleasure;
    }

    public Double getVlazhn() {
        return vlazhn;
    }
}
