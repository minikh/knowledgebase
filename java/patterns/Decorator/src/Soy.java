/**
 * User: Миних Владимир
 * Date: 09.07.13
 * Time: 10:42
 */
public class Soy extends Decorator {

    private IBeverage beverage;
    private double price = 5.0;
    private double size = 1.0;

    public Soy(IBeverage beverage) {
        this.beverage = beverage;
        size = this.beverage.getSize();
        price *= size;
    }

    @Override
    public String getDescription() {
        return beverage.getDescription() + "Соя " + price + " руб.\n";
    }

    @Override
    public double cost() {
        return price + beverage.cost();
    }

    @Override
    public void setSize(Size size) {
        this.size = size.getSize();
    }

    @Override
    public double getSize() {
        return size;  //To change body of implemented methods use File | Settings | File Templates.
    }
}
