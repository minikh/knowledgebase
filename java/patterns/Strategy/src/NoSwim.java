/**
 * User: Миних Владимир
 * Date: 08.07.13
 * Time: 10:24
 */
public class NoSwim implements ISwim {

    @Override
    public String toString() {
        return "Переключаюсь на неумение плавать";
    }

    @Override
    public void swim() {
        System.out.println("не умею плавать");
    }
}
