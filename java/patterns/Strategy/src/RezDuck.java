/**
 * User: Миних Владимир
 * Date: 08.07.13
 * Time: 15:23
 */
public class RezDuck extends Duck {
    @Override
    public void display() {
        System.out.println("Это резиновая утка");
    }

    public RezDuck() {
        super(new NoFly(), new Pisk(), new Swim());
    }
}
