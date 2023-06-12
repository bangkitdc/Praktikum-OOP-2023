public class Karavan extends TempatTinggal implements Kendaraan {
	private float bensin;
	private float pemakaianBensin;

	// @Override
    public double hitungBiayaBangun() {
        return super.hitungBiayaBangun() * 3;
    }

    // @Override
    public float hitungJarakTempuh() {
        return bensin * pemakaianBensin;
    }

	public void setPemakaianBensin(float pemakaianBensin) {
        this.pemakaianBensin = pemakaianBensin;
    }
    public void setBensin(float bensin) {
        this.bensin = bensin;
    }

    public float getPemakaianBensin() {
        return pemakaianBensin;
    }

    public float getBensin() {
        return bensin;
    }

    public static void main(String[] args) {
        Karavan k = new Karavan();

        k.setLuas(50);
        k.setHargaBahanBangunan(50);

        System.out.println(k.hitungBiayaBangun());
        System.out.println(k.hitungJarakTempuh());
    }
}