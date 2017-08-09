import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * User: Миних Владимир
 * Date: 09.07.13
 * Time: 9:51
 */
public class ButtonListiner implements ActionListener {
    @Override
    public void actionPerformed(ActionEvent e) {
        System.out.println("Слушатель ButtonListiner");
    }
}
