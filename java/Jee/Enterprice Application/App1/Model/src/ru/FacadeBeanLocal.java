package ru;

import javax.ejb.Local;

/**
 * Created by minik_000 on 02.05.2014.
 */
//@Local
public interface FacadeBeanLocal {
    String info();
    void startJob();
    void stopJob();
    String testAsync();
}
