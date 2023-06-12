/**
 * Gajah.java
 * [Jelaskan kegunaan class ini]
 * @author [NIM] [Nama]
 */

public class Gajah extends Animal {
    private int basePower;
    private int age;

    public Gajah(int b, int a) {
        this.numberOfLegs = 4;
        this.basePower = b;
        this.age = a;
    }

    public int getAge() {
        return age;
    }

    public int getAnimalPower() {
        return 3 * (basePower + age + this.children);
    }

    // public static void main(String[] args) {
    //     Gajah g = new Gajah(5, 10);

    //     System.out.println(g.getAnimalPower());
    // }
}
