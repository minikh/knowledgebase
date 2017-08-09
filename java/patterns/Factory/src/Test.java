import pizza.facrory.ChicagoPizzaFactory;
import pizza.facrory.NyPizzaFactory;
import pizza.PizzaType;
import pizza.facrory.PizzaFactory;

/**
 * Created with IntelliJ IDEA.
 * User: vega
 * Date: 10.07.13
 * Time: 14:05
 * To change this template use File | Settings | File Templates.
 */
public class Test {

    public static void main(String[] a){

        PizzaStory pizzaStory;

        PizzaFactory nyPizzaFactory = new NyPizzaFactory();
        pizzaStory = new PizzaStory(nyPizzaFactory);

        pizzaStory.orderPizza(PizzaType.Pepperoni);
        System.out.println("-------");

        PizzaFactory chicagoPizzaFactory = new ChicagoPizzaFactory();
        pizzaStory = new PizzaStory(chicagoPizzaFactory);

        pizzaStory.orderPizza(PizzaType.Clam);
        System.out.println("-------");
        pizzaStory.orderPizza(PizzaType.Veggie);
        System.out.println("-------");

    }
}
