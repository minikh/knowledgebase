import pizza.IPizza;
import pizza.facrory.NyPizzaFactory;
import pizza.Pizza;
import pizza.PizzaType;
import pizza.facrory.PizzaFactory;

/**
 * Created with IntelliJ IDEA.
 * User: vega
 * Date: 10.07.13
 * Time: 14:02
 * To change this template use File | Settings | File Templates.
 */
public class PizzaStory {

    private PizzaFactory factory;

    public PizzaStory(PizzaFactory factory) {
        this.factory = factory;
    }

    public IPizza orderPizza(PizzaType type){
        IPizza pizza;

        pizza = factory.createPizza(type);

        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();

        return pizza;
    }
}
