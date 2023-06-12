public class Kompleks {

    private static int n_kompleks = 0;
    private int real;
    private int imaginer;

    // ctor tanpa parameter
    // inisialisasi seluruh koefisien dengan nilai 0
    public Kompleks() {
        this(0, 0);
    }

    // ctor dengan parameter
    public Kompleks(int real, int imaginer) {
        this.real = real;
        this.imaginer = imaginer;  
        n_kompleks ++;
    }
    
    //mengembalikan bagian riil
    public int getReal() {
        return real;
    }

    // mengembalikan bagian imaginer
    public int getImaginer() {
        return imaginer;
    }

    // mengisi bagian riil
    public void setReal(int real) {
        this.real = real;
    }

    // mengisi bagian imaginer
    public void setImaginer(int imaginer) {
        this.imaginer = imaginer;
    }

    // operator+ untuk melakukan penjumlahan dengan rumus berikut
    public Kompleks plus(Kompleks b) {
        Kompleks res = new Kompleks();

        res.setReal(getReal() + b.getReal());
        res.setImaginer(getImaginer() + b.getImaginer());

        return res;
    }

    // operator- untuk melakukan pengurangan dengan rumus berikut
    public Kompleks minus(Kompleks b) {
        Kompleks res = new Kompleks();

        res.setReal(getReal() - b.getReal());
        res.setImaginer(getImaginer() - b.getImaginer());

        return res;
    }

    // operator* untuk melakukan perkalian dengan rumus berikut
    public Kompleks multiply(Kompleks b) {
        Kompleks res = new Kompleks();

        res.setReal((getReal() * b.getReal()) - (getImaginer() * b.getImaginer()));
        res.setImaginer((getImaginer() * b.getReal()) + (getReal() * b.getImaginer()));

        return res;
    }

    // operator* untuk mengkalikan bilangan kompleks dengan konstanta
    public Kompleks multiply (int x) {
        Kompleks res = new Kompleks();

        res.setReal(getReal() * x);
        res.setImaginer(getImaginer() * x);

        return res;
    }

    // mengembalikan jumlah instance yang pernah dibuat
    public static int countKompleksInstance() {
        return n_kompleks;
    }

    // mencetak bilangan kompleks ke layar, diakhiri dengan end-of-line 
    // contoh:
    // 3+5i
    // 0
    // 3i
    // -3
    // -5-4i
    public void print() {
        if (real == 0 && imaginer == 0) {
            System.out.println(0);
        } else if (real == 0) {
            System.out.println(imaginer + "i");
        } else if (imaginer == 0) {
            System.out.println(real);
        } else {
            System.out.print(real);
        
            if(imaginer > 0) {
                System.out.print("+");
            }

            System.out.println(imaginer + "i");
        }
    } 

    public static void main(String[] args) {
        Kompleks k = new Kompleks(2, -1);

        k.print();

        System.out.println(Kompleks.n_kompleks);
        System.out.println(k.countKompleksInstance());

        Kompleks k2 = new Kompleks(5, 3);

        k = k.multiply(k2);

        k.print();
    }
}