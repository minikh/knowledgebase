/**
 * User: ����� ��������
 * Date: 08.07.13
 * Time: 15:28
 */
public class WoodDuck extends Duck {

    @Override
    public void display() {
        System.out.println("���������� ����");
    }

    public WoodDuck() {
        super(new Jet(), new SoundJet(), new Swim());
    }
}
