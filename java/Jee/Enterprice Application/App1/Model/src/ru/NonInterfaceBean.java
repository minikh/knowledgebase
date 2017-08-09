package ru;

import javax.ejb.LocalBean;
import javax.ejb.Stateless;

/**
 * Created by minik_000 on 04.05.2014.
 */
@Stateless(name = "NonInterfaceEJB")
@LocalBean //локальный бин (без интерфейсов)
public class NonInterfaceBean {
    public NonInterfaceBean() {
    }

    public String info(int a){
        return "Нет интерфейса" + a;
    }
}
