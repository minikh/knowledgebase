package pizza;

/**
 * Created with IntelliJ IDEA.
 * User: vega
 * Date: 10.07.13
 * Time: 13:54
 * To change this template use File | Settings | File Templates.
 */
public enum PizzaType {

    Cheese("Cheese"),
    Pepperoni("Pepperoni"),
    Clam("Clam"),
    Veggie("Veggie");

    private String type;

    private PizzaType(String type) {
        this.type = type;
    }

    @Override
    public String toString() {
        return type;
    }
}
