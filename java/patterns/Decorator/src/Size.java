/**
 * User: admin
 * Date: 09.07.13
 * Time: 22:51
 */
public enum Size {

    Small("���������", 0.3),
    Middle("�������", 0.5),
    Big("�������", 1.0);

    private String description;
    private double size;

    private Size(String description, double size) {
        this.description = description;
        this.size = size;
    }

    public String getDescription() {
        return description;
    }

    public double getSize() {
        return size;
    }
}
