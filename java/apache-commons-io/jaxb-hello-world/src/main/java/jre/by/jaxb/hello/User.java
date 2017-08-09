package jre.by.jaxb.hello;

import javax.xml.bind.annotation.*;
import java.util.ArrayList;
import java.util.List;

@XmlRootElement
@XmlType(name = "user", propOrder = {"id", "name", "age", "childs"})
public class User {
    private Name name;
    private int age;
    private int id;
    private List<User> childs;

    public Name getName() {
        return name;
    }

    @XmlElement
    public void setName(Name name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    @XmlElement
    public void setAge(int age) {
        this.age = age;
    }

    public int getId() {
        return id;
    }

    @XmlAttribute
    public void setId(int id) {
        this.id = id;
    }

    public List<User> getChilds() {
        return childs;
    }

    @XmlElementWrapper(name = "childs")
    @XmlElement(name = "child")
    public void setChilds(List<User> childs) {
        this.childs = childs;
    }

    public void addChild(User child){
        if (childs==null) {
            childs = new ArrayList<User>();
        }
        childs.add(child);
    }

    @Override
    public String toString() {
        return "User{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", id=" + id +
                '}';
    }
}
