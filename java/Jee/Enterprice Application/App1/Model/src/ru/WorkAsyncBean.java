package ru;

import ru.data.Person;

import javax.ejb.AsyncResult;
import javax.ejb.Asynchronous;
import javax.ejb.Local;
import javax.ejb.Stateless;
import java.util.concurrent.Future;

/**
 * Created by minik_000 on 04.05.2014.
 */
@Local(WorkAsyncBeanLocal.class)
@Stateless(name = "WorkAsyncEJB")
public class WorkAsyncBean implements WorkAsyncBeanLocal {
    public WorkAsyncBean() {
    }

    @Override
    @Asynchronous
    public Future infoWithFuture(){
        System.out.println("--------- BEFORE -------------");
        Person person = new Person("Иванов","Иван","Иванович");
        AsyncResult result = new AsyncResult(person);
        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("--------- AFTER -------------");
        return result;
    }

    @Override
    @Asynchronous
    public void info() {
        System.out.println("-------------------------------");
        for (int i = 0; i < 10; i++) {
            try {
                Thread.sleep(500);
                System.out.println("======" + i);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
