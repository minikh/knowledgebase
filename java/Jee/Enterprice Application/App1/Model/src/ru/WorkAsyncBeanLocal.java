package ru;

import java.util.concurrent.Future;

/**
 * Created by minik_000 on 04.05.2014.
 */
public interface WorkAsyncBeanLocal {
    void info();

    Future infoWithFuture();
}
