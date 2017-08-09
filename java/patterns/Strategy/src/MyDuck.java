/**
 * User: Миних Владимир
 * Date: 08.07.13
 * Time: 15:23
 */
public class MyDuck extends Duck {
    @Override
    public void display() {
        System.out.println("Это утка живая");
    }

    public MyDuck() {
        super(new Fly(), new Cryak(), new Swim());
    }
}
