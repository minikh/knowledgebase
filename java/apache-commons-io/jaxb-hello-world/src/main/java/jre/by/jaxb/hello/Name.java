package jre.by.jaxb.hello;

import javax.xml.bind.annotation.XmlAttribute;
import javax.xml.bind.annotation.XmlType;

/**
 * Created by USER on 16.04.2014.
 *
 */
@XmlType(name = "name", propOrder = {"firstName", "secondName"})
public class Name {
    private String firstName;
    private String secondName;

    public Name() {
    }

    public Name(String firstName, String secondName) {
        this.firstName = firstName;
        this.secondName = secondName;
    }

    @XmlAttribute
    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getFirstName() {
        return firstName;
    }

    @XmlAttribute
    public void setSecondName(String secondName) {
        this.secondName = secondName;
    }

    public String getSecondName() {
        return secondName;
    }

    @Override
    public String toString() {
        return firstName + " " + secondName;
    }
}
