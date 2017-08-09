package ru;

import ru.data.Person;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;
import javax.annotation.Resource;
import javax.ejb.*;
import javax.sql.DataSource;
import java.util.Collection;
import java.util.Date;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;

/**
 * Created by minik_000 on 02.05.2014.
 */
//@Remote(FacadeBeanRemote.class)
@Local(FacadeBeanLocal.class)
@Stateless(name = "F1")
public class FacadeBean implements FacadeBeanLocal {

    @EJB
    private NonInterfaceBean nonInterfaceBean;

    @Resource
    private SessionContext sessionContext;
    @Resource(name = "jboss/postgresql")
    private DataSource ds;
    TimerHandle timerHandle;
    @EJB
    private WorkAsyncBeanLocal workAsyncEJB;


    private Long id;
    public FacadeBean() {
        id = System.currentTimeMillis();
        System.out.println("----- Constructor id = " + id + " создан. DS = " + ds + ". SesionContext = " + sessionContext);
    }

    @PostConstruct
    public void myInit(){
        System.out.println("----- Post construct id = " + id + ". DS = " + ds + ". SesionContext = " + sessionContext);
    }

    @PreDestroy
    public void myDestroy(){
        System.out.println("====== Predestroy id = " + id);
    }

    @Override
    public String info() {
        System.out.println("Метод info() id = " + id);
        return "Привет Мир id = " + id + ". DS = " + ds + "<br> SesionContext = " + sessionContext;
    }

    @Override
    public void startJob() {

        if (timerHandle == null) {
            timerHandle = sessionContext.getTimerService().createTimer(new Date(), 2000, "TimerJob").getHandle();
            System.out.println("startJob");
        }
        System.out.println("startJob 1");
    }

    @Override
    public void stopJob() {
        System.out.println("**************** " + timerHandle);
//        if (timerHandle != null) {
//            timerHandle.getTimer().cancel();
//            timerHandle = null;
//            System.out.println("stopJob");
//        }
//        System.out.println("stopJob 1");
        Collection<Timer> timers = sessionContext.getTimerService().getTimers();
        for(Timer t: timers){
            t.cancel();
        }
    }

    @Timeout
    public void timerJob(Timer t){
        if(t.getInfo().equals("TimerJob")){
            System.out.println("+++++++++ " + new Date());
        }
    }

    @Override
    public String testAsync() {
//        workAsyncEJB.info();
        Future result = workAsyncEJB.infoWithFuture();
        try {
//            Person person = (Person) result.get();
            Person person = (Person) result.get(4, TimeUnit.SECONDS);
            return "Метод test выполен " + person.getfName() + " " + nonInterfaceBean.info(13);
        } catch (InterruptedException e) {
            return "InterruptedException" + e;
        } catch (ExecutionException e) {
            return "ExecutionException" + e;
        } catch (TimeoutException e) {
            return "Время истекло. " + e;
        }
//        return "Метод test выполен";
    }
}
