package pizza.chicago;

import pizza.Pizza;

/**
 * Created with IntelliJ IDEA.
 * User: vega
 * Date: 10.07.13
 * Time: 14:00
 * To change this template use File | Settings | File Templates.
 */
public class ChicagoVeggiePizza extends Pizza {

    public ChicagoVeggiePizza() {
        System.out.println("ChicagoVeggiePizza");
    }

    @Override
    public void cut() {
        System.out.println("Режем квадратиками");
    }
}
