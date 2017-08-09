/**
 * User: admin
 * Date: 08.07.13
 * Time: 21:42
 * Вывод информации о погоде
 */
public class CurrentDisplay implements IObserver, IDisplayElement {

    private ISubject subject;
    private Double temp;
    private Double pleasure;
    private Double vlazhn;

    public CurrentDisplay(ISubject subject) {
        this.subject = subject;
    }

    @Override
    public void display() {

        System.out.println("-------CurrentDisplay--------");
        System.out.print("Температура " + temp);
        System.out.print(", давление " + pleasure);
        System.out.println(", влажность " + vlazhn);
    }

    @Override
    public void update(Double temp, Double pleasure, Double vlazhn) {
        this.temp = temp;
        this.pleasure = pleasure;
        this.vlazhn = vlazhn;
        display();
    }

    @Override
    public void register() {
        subject.registerObserver(this);
    }

    @Override
    public void remove() {
        subject.removeObserver(this);
    }
}
