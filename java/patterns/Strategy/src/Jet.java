/**
 * User: Миних Владимир
 * Date: 08.07.13
 * Time: 13:31
 */
public class Jet implements IFly {
    @Override
    public void fly() {
        System.out.println("реактивная тяга");
    }

    @Override
    public String toString() {
        return "Переключаюсь на реактивную тягу";
    }
}
