public class GreenCard extends Card {
	public GreenCard(Double val) {
		super(val);
	}

	@Override
    public Double value() {
        return number + 0.0;
    }

    @Override
    public void printInfo() {
        System.out.println("Kartu Hijau: " + number);
    }
}