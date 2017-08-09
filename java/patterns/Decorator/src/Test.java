/**
 * User: Миних Владимир
 * Date: 09.07.13
 * Time: 10:44
 */
public class Test {

    public static void main(String[] a){

        IBeverage espresso = new Espresso();
        espresso.setSize(Size.Small);
        espresso = new Milk(espresso);
        espresso = new Milk(espresso);
        espresso = new Soy(espresso);
        System.out.println(espresso.getDescription() + "---------\nЦена " + espresso.cost() + " руб.");

        System.out.println(" ");

        IBeverage cappuccino = new Cappuccino();
        cappuccino.setSize(Size.Big);
        cappuccino = new Milk(cappuccino);
        cappuccino = new Soy(cappuccino);
        System.out.println(cappuccino.getDescription() + "---------\nЦена " + cappuccino.cost() + " руб.");
    }
}
