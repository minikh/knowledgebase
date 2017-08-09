package ru;

import javax.ejb.Local;
import javax.ejb.Remote;
import javax.ejb.Stateless;

/**
 * Created by minik_000 on 02.05.2014.
 */
@Remote(FacadeBeanRemote.class)
@Stateless(name = "F1")
public class FacadeBean implements FacadeBeanRemote {
    private Long id;
    public FacadeBean() {
        id = System.currentTimeMillis();
        System.out.println("----- Constructor id = " + id + " создан");
    }

    @Override
    public String info() {
        System.out.println("Метод info() id = " + id);
        return "Привет Мир id = " + id;
    }
}
