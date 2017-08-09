package pizza.facrory;

import pizza.IPizza;
import pizza.Pizza;
import pizza.PizzaType;
import pizza.ny.NyCheesePizza;
import pizza.ny.NyClamPizza;
import pizza.ny.NyPepperoniPizza;
import pizza.ny.NyVeggiePizza;

/**
 * Created with IntelliJ IDEA.
 * User: vega
 * Date: 10.07.13
 * Time: 13:55
 * To change this template use File | Settings | File Templates.
 */
public class NyPizzaFactory implements PizzaFactory {

    @Override
    public IPizza createPizza(PizzaType type){

        IPizza pizza = null;

        switch (type){
            case Cheese:
                pizza = new NyCheesePizza();
                break;
            case Pepperoni:
                pizza = new NyPepperoniPizza();
                break;
            case Clam:
                pizza = new NyClamPizza();
                break;
            case Veggie:
                pizza = new NyVeggiePizza();
                break;
        }

        return pizza;
    }
}
