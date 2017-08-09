import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * User: Миних Владимир
 * Date: 04.07.13
 * Time: 14:59
 */
public class SwingDemo implements ActionListener {

    private JFrame jFrame = new JFrame("Тестовое окошечко");

    public SwingDemo() {

        jFrame.setSize(500, 200);

        jFrame.setLocation(500, 500);

        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JButton jButton = new JButton("Кнопочка");
        jButton.addActionListener(this);

        jFrame.add(jButton);

        jFrame.setVisible(true);
    }

    public static void main(String[] args){
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new SwingDemo();
            }
        });
    }

    /**
     * Invoked when an action occurs.
     */
    @Override
    public void actionPerformed(ActionEvent e) {
        jFrame.setLocation(jFrame.getX() + 10, jFrame.getY() + 10);
    }
}
