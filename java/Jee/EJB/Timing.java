import javax.ejb.Timeout;
import javax.ejb.Timer;
import javax.ejb.TimerService;

@Stateless(name="DelayedHelloWorld")
public class DelayedHelloWorldBean implements DelayedHelloWorld, DelayedHelloWorldLocal {
    @Resource TimerService ts;
    
    public DelayedHelloWorldBean() {}
    public void scheduleDelayedHello(String hello) {
        ts.createTimer(3000, hello);
    }
    @Timeout public void sayHello(Timer timer) {
        String hello = (String) timer.getInfo();
        System.out.println(hello);
    }
}
