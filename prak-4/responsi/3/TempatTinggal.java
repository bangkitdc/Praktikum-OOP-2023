public class TempatTinggal {
	protected int luas;
	protected double hargaBahanBangunan;

	public TempatTinggal() {
		this(0, 0);
	}

	public TempatTinggal(int luas, double hargaBahanBangunan) {
		this.luas = luas;
		this.hargaBahanBangunan = hargaBahanBangunan;
	}

	public int getLuas() {
		return luas;
	}

	public double getHargaBahanBangunan() {
		return hargaBahanBangunan;
	}

	public void setLuas(int luas) {
		this.luas = luas;
	}

	public void setHargaBahanBangunan(double hargaBahanBangunan) {
		this.hargaBahanBangunan = hargaBahanBangunan;
	}

	public double hitungBiayaBangun() {
		return luas * hargaBahanBangunan;
	}

}