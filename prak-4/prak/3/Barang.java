class Barang {
	private String nama;
	private int amount;

	public Barang(String nama, int amount) {
		this.nama = nama;
		this.amount = amount;
	}

	public String toString() {
		return String.format("%d %s", amount, nama);
	}
}