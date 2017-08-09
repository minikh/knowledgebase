package pizza;

public abstract class Pizza implements IPizza {

    @Override
    public void prepare(){
        System.out.println("Стряпаем");
    }

    @Override
    public void bake(){
        System.out.println("Выпекаем");
    }

    @Override
    public void cut(){
        System.out.println("Режем треугольниками");
    }

    @Override
    public void box(){
        System.out.println("Упаковка");
    }

}
