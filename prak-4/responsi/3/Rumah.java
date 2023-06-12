public class Rumah extends TempatTinggal {

	public Rumah(int luas, double hargaBahanBangunan) {
        super(luas, hargaBahanBangunan);
    }

    public Rumah(int lebar, int panjang, double hargaBahanBangunan) {
    	super(lebar * panjang, hargaBahanBangunan);
    }

    // hitungBiayaBangun bisa diturunin dari parent

    public double hitungBiayaBangun(double biayaOrmas) {
        return super.hitungBiayaBangun() + biayaOrmas;
    }

    public void setLuas(int panjang, int lebar) {
        this.luas = lebar * panjang;
    }
}