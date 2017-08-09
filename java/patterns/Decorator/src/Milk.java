/**
 * User: Миних Владимир
 * Date: 09.07.13
 * Time: 10:37
 */
public class Milk extends Decorator {

    private IBeverage beverage;
    private double price = 10.0;
    private double size = 1.0;

    public Milk(IBeverage beverage) {
        this.beverage = beverage;
        size = this.beverage.getSize();
        price *= size;
    }

    @Override
    public String getDescription() {
        return beverage.getDescription() + "Молоко " + price + " руб.\n";
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
