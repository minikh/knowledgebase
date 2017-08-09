/**
 * User: ћиних ¬ладимир
 * Date: 09.07.13
 * Time: 10:34
 */
public class Espresso implements IBeverage {

    private String description;
    private double price = 50.0;
    private double size = 1.0;

    @Override
    public String getDescription() {
        return description;  //To change body of implemented methods use File | Settings | File Templates.
    }


//    public Espresso() {
//        description = "Ёкспрессо " + price + " руб.\n";
//    }

    @Override
    public double cost() {
        return price;
    }

    @Override
    public void setSize(Size size) {
        this.size = size.getSize();
        price *= this.size;
        description = "Ёкспрессо " + size.getDescription() + " " + price + " руб.\n";
    }

    @Override
    public double getSize() {
        return size;  //To change body of implemented methods use File | Settings | File Templates.
    }
}
