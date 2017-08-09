package ru.model;

import javax.ejb.Remote;

/**
 * Created by minik_000 on 02.05.2014.
 */
@Remote
public interface FacadeRemote {
    String info();
}
