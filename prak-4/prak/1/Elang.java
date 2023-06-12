/**
 * Elang.java
 * [Jelaskan kegunaan class ini]
 * @author [NIM] [Nama]
 */

public class Elang extends Animal {
    private int basePower;
    private int jumlahTelur;

    public Elang(int b) {
        this.numberOfLegs = 2;
        this.basePower = b;
        this.jumlahTelur = 0;
    }

    public int getJumlahTelur() {
        return jumlahTelur;
    }

    public void bertelur() {
        jumlahTelur ++;
    }

    public int getAnimalPower() {
        return basePower * this.children - jumlahTelur;
    }

    // public static void main(String[] args) {
    //     Elang e = new Elang(5, 2);


    //     System.out.println(e.getAnimalPower());
    // }
}
