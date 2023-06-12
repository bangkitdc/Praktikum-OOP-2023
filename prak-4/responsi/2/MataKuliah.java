import java.lang.Comparable;

class MataKuliah implements Comparable<MataKuliah> {
    private float rating;
    private String nama;
    private int kodeJurusan;
    private int tahunPengambilan;

    public MataKuliah(String nama, int kodeJurusan, int tahunPengambilan, float rating) {
        this.rating = rating;
        this.nama = nama;
        this.kodeJurusan = kodeJurusan;
        this.tahunPengambilan = tahunPengambilan;
    }

    public String getNama() {
        return nama;
    }

    public int getKodeJurusan() {
        return kodeJurusan;
    }

    public int getTahunPengambilan() {
        return tahunPengambilan;
    }
    
    public float getRating() {
        return rating;
    }

    public int compareTo(MataKuliah m) {
        // compareTo mengembalikan:
        // 0 bila this sama dengan m
        // 1 bila this lebih dari m
        // -1 bila this kurang dari m

        if (kodeJurusan < m.kodeJurusan) {
            return -1;
        } else if ((kodeJurusan == m.kodeJurusan) && (tahunPengambilan < m.tahunPengambilan)) {
            return -1;
        } else if ((kodeJurusan == m.kodeJurusan) && (tahunPengambilan == m.tahunPengambilan) && (rating < m.rating)) {
            return -1;
        }

        if ((rating == m.rating) && (kodeJurusan == m.kodeJurusan) && (tahunPengambilan == m.tahunPengambilan)) {
            return 0;
        } 

        return 1;
    }

    public static void main(String[] args) {
        MataKuliah m = new MataKuliah("halo", 1, 1, 0);
        MataKuliah p = new MataKuliah("halo", 1, 0, 1);

        System.out.println(m.compareTo(p));
    }
}