package ru.model;

import javax.ejb.Stateless;

/**
 * Created by minik_000 on 02.05.2014.
 */
@Stateless(mappedName = "F1")
public class Facade implements FacadeLocal, FacadeRemote {
    private Long id;
    public Facade() {
        id = System.currentTimeMillis();
        System.out.println("----- Constructor id = " + id + " создан");
    }

    @Override
    public String info() {
        System.out.println("Метод info() id = " + id);
        return "Привет Мир id = " + id;
    }
}
