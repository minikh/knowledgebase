/**
 * User: ����� ��������
 * Date: 09.07.13
 * Time: 10:33
 */
public abstract class Beverage implements IBeverage {

    private String description;


    @Override
    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

//    @Override
//    public abstract double cost();

//    @Override
//    public abstract void setSize(double size);
//
//    @Override
//    public abstract double getSize();
}
