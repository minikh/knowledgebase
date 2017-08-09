package ru.data;

import java.io.Serializable;

/**
 * Created by minik_000 on 04.05.2014.
 */
public class Person implements Serializable {
    private String fName;
    private String sName;
    private String info;

    public Person(String fName, String sName, String info) {
        this.fName = fName;
        this.sName = sName;
        this.info = info;
    }

    public String getfName() {
        return fName;
    }

    public void setfName(String fName) {
        this.fName = fName;
    }

    public String getsName() {
        return sName;
    }

    public void setsName(String sName) {
        this.sName = sName;
    }

    public String getInfo() {
        return info;
    }

    public void setInfo(String info) {
        this.info = info;
    }
}
