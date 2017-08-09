package ru;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;
import javax.ejb.*;

/**
 * Created by minik_000 on 04.05.2014.
 */
@Local(FacadeStateFullBeanLocal.class)
//@Stateful(name = "F2")
//@Stateful
@Stateless(name = "F2")
public class FacadeStateFullBean implements FacadeStateFullBeanLocal {
    public FacadeStateFullBean() {
    }

    @Override
    public void myRemove() {
        System.out.println("метод myRemove");
    }

    @Override
    public String info() {
        return "Привет FacadeStateFullBean";
    }

    @PostConstruct
    public void init(){
        System.out.println("------ INIT FacadeStateFullBean --------");
    }

    @PreDestroy
    public void destroy(){
        System.out.println("------- DESTROY FacadeStateFullBean --------");
    }

    @PostActivate
    public void activate(){
        System.out.println("------- ACTIVATE FacadeStateFullBean --------");
    }

    @PrePassivate
    public void passivate(){
        System.out.println("------- PASSIVATE FacadeStateFullBean --------");
    }
}
