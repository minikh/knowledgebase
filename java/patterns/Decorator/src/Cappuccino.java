/**
 * User: Миних Владимир
 * Date: 09.07.13
 * Time: 10:35
 */
public class Cappuccino implements IBeverage {

    private String description;
    private double size = 1.0;
    private double price = 40.0;

    @Override
    public void setSize(Size size) {
        this.size = size.getSize();
        price *= this.size;
        description = "Капучино " + size.getDescription() + " " + price + " руб.\n";
    }

    @Override
    public double getSize() {
        return size;  //To change body of implemented methods use File | Settings | File Templates.
    }



//    public Cappuccino() {
//        description = "Капучино " + price + " руб.\n";
//    }

    @Override
    public String getDescription() {
        return description;  //To change body of implemented methods use File | Settings | File Templates.
    }

    @Override
    public double cost() {
        return price;
    }
}
