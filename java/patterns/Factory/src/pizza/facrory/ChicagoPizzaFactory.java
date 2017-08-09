package pizza.facrory;

import pizza.IPizza;
import pizza.Pizza;
import pizza.PizzaType;
import pizza.chicago.ChicagoCheesePizza;
import pizza.chicago.ChicagoClamPizza;
import pizza.chicago.ChicagoPepperoniPizza;
import pizza.chicago.ChicagoVeggiePizza;


/**
 * Created with IntelliJ IDEA.
 * User: vega
 * Date: 10.07.13
 * Time: 13:55
 * To change this template use File | Settings | File Templates.
 */
public class ChicagoPizzaFactory implements PizzaFactory {

    @Override
    public IPizza createPizza(PizzaType type){

        IPizza pizza = null;

        switch (type){
            case Cheese:
                pizza = new ChicagoCheesePizza();
                break;
            case Pepperoni:
                pizza = new ChicagoPepperoniPizza();
                break;
            case Clam:
                pizza = new ChicagoClamPizza();
                break;
            case Veggie:
                pizza = new ChicagoVeggiePizza();
                break;
        }

        return pizza;
    }
}
