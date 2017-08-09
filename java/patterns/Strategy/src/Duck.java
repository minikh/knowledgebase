/**
 * User: Миних Владимир
 * Date: 08.07.13
 * Time: 10:27
 */
public abstract class Duck {

    private IFly fly;
    private ISound sound;
    private ISwim swim;

    public Duck(IFly fly, ISound sound, ISwim swim) {
        this.fly = fly;
        this.sound = sound;
        this.swim = swim;
    }

    public abstract void display();

    public void sound(){
        sound.sound();
    }

    public void fly() {
        fly.fly();
    }

    public void swim() {
        swim.swim();
    }

    public void setFly(IFly fly) {
        System.out.println(fly);
        this.fly = fly;
    }

    public void setSound(ISound sound) {
        System.out.println(sound);
        this.sound = sound;
    }

    public void setSwim(ISwim swim) {
        System.out.println(swim);
        this.swim = swim;
    }


}
