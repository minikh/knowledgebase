/**
 * User: ����� ��������
 * Date: 08.07.13
 * Time: 15:23
 */
public class RezDuck extends Duck {
    @Override
    public void display() {
        System.out.println("��� ��������� ����");
    }

    public RezDuck() {
        super(new NoFly(), new Pisk(), new Swim());
    }
}
