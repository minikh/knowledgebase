/**
 * User: Миних Владимир
 * Date: 09.07.13
 * Time: 10:14
 */
public class WidjetAll implements Observer, DisplayData {

    private Subject subject;
    private Double t;
    private Double p;
    private Double v;

    public WidjetAll(Subject subject) {
        this.subject = subject;

    }

    @Override
    public void update(Double t, Double p, Double v) {
        this.p = p;
        this.t = t;
        this.v = v;

        display();
    }

    @Override
    public void display() {
        System.out.println("Температура " + t);
    }

    public void register(){
        subject.addObserver(this);
    }

    public void unRegister(){
        subject.removeObserver(this);
    }
}
