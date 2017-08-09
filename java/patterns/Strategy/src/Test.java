/**
 * User: Миних Владимир
 * Date: 08.07.13
 * Time: 10:31
 */
public class Test {

    public static void main(String[] a){
        Duck duck1 = new MyDuck();
        duck1.display();
        duck1.swim();
        duck1.sound();
        duck1.fly();

        duck1.setSwim(new NoSwim());
        duck1.swim();

        System.out.println("------------");

        Duck duckJet = new WoodDuck();
        duckJet.display();
        duckJet.swim();
        duckJet.fly();
        duckJet.setFly(new Jet());
        duckJet.fly();
        duckJet.sound();
    }

}
