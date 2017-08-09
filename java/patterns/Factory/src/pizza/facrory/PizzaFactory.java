package pizza.facrory;

import pizza.IPizza;
import pizza.PizzaType;

/**
 * Created with IntelliJ IDEA.
 * User: vega
 * Date: 10.07.13
 * Time: 14:24
 * To change this template use File | Settings | File Templates.
 */
public interface PizzaFactory {

    public IPizza createPizza(PizzaType type);
}
