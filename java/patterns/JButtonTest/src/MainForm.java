import javax.swing.*;

/**
 * User: ����� ��������
 * Date: 09.07.13
 * Time: 9:50
 */
public class MainForm {

    JFrame jFrame = new JFrame("����");
    JButton jButton = new JButton("������");

    public void test(){

        jFrame.add(jButton);

        jButton.addActionListener(new ButtonListiner());
        jButton.addActionListener(new NewListyner());

        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jFrame.setVisible(true);
    }

    public static void main(String[] args){

        MainForm mainForm = new MainForm();
        mainForm.test();

    }
}
