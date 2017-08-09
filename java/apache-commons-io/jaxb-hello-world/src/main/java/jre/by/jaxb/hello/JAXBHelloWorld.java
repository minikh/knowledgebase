package jre.by.jaxb.hello;

import org.apache.commons.io.FileUtils;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;
import javax.xml.bind.Unmarshaller;
import java.io.File;

public class JAXBHelloWorld {
    public static void main(String[] args) {
        try {
            int id = 0;

            User user = new User();
            user.setId(++id);
            user.setName(new Name("Иванов", "Иван"));
            user.setAge(29);

            User child1 = new User();
            child1.setId(++id);
            child1.setAge(3);
            child1.setName(new Name("Иванов", "Андрей"));
            user.addChild(child1);

            User child2 = new User();
            child2.setId(++id);
            child2.setAge(5);
            child2.setName(new Name("Иванов", "Сергей"));
            user.addChild(child2);

            File file = new File("file.xml");
            marshal(user, file);
            System.out.println("----------------------------\n");
            System.out.println("marshal example");
            System.out.println(FileUtils.readFileToString(file));
            System.out.println("----------------------------\n");
            System.out.println("unMarshal example");
            user = (User) unMarshal(file);
            System.out.println(user);
            System.out.println("\n--------дети----------------");
            for(User child: user.getChilds()){
                System.out.println(child);
            }
            System.out.println("\n----------------------------");
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
// конвертация в XML
    public static void marshal(Object obj, File file) throws JAXBException {
        JAXBContext context = JAXBContext.newInstance(User.class);
        Marshaller marshaller = context.createMarshaller();
        // для удобно читаемого вида
        marshaller.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
        marshaller.marshal(obj, file);
    }
    // конвертация в JAVA  объект
    public static Object unMarshal(File file) throws JAXBException {
        JAXBContext jaxbContext = JAXBContext.newInstance(User.class);
        Unmarshaller jaxbUnmarshaller = jaxbContext.createUnmarshaller();
        return jaxbUnmarshaller.unmarshal(file);
    }
}
