/**
 * User: ����� ��������
 * Date: 08.07.13
 * Time: 15:23
 */
public class MyDuck extends Duck {
    @Override
    public void display() {
        System.out.println("��� ���� �����");
    }

    public MyDuck() {
        super(new Fly(), new Cryak(), new Swim());
    }
}
