class DaftarBelanja {
	private Barang[] listBelanja;
	static int count = 0;

	public DaftarBelanja(int max) {
		this.listBelanja = new Barang[max];
	}

	public void belanja(int lorong, String keterangan) {
		belanja(lorong, 1, keterangan);
	}

	public void belanja(int lorong, int qty, String keterangan) {
		if (!(count == listBelanja.length)) {
			Barang temp = new Barang(keterangan + " (lorong " + lorong + ")", qty);
			this.listBelanja[count] = temp;
			count ++;
		}
	}

	public void belanja(String barang) {
		belanja(barang, 1);
	}

	public void belanja(String barang, int qty) {
		if (!(count == listBelanja.length)) {
			Barang temp = new Barang(barang, qty);
			this.listBelanja[count] = temp;
			count ++;
		}
	}

	public void print() {
		// cara 1
		int res = 1;

		for (Barang b : listBelanja) {
			if (b != null) {
				System.out.println(res + ". " + b);
				res ++;
			}
		}

		// cara 2
		// for (int i = 0; i < count; i ++) {
		// 	System.out.println((i + 1) + ". " + listBelanja[i]);
		// }
	}

	public static void main(String[] args) {
		DaftarBelanja d = new DaftarBelanja(3);

		d.belanja("shampo heri", 100);
		d.belanja(25, 5, "kotak merah");
		// d.belanja(5, "kotak merah");
		d.belanja("halo");

		d.print();
	}
}