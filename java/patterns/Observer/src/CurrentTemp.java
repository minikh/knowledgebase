/**
 * User: admin
 * Date: 08.07.13
 * Time: 22:10
 * Вывод информации об изменении температуры
 */
public class CurrentTemp implements IObserver, IDisplayElement {

    private ISubject subject;
    private Double temp;

    public CurrentTemp(ISubject subject) {
        this.subject = subject;
    }

    @Override
    public void display() {
        System.out.println("-------CurrentTemp--------");
        System.out.println("Температура " + temp);
    }

    @Override
    public void update(Double temp, Double pleasure, Double vlazhn) {
        this.temp = temp;
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
