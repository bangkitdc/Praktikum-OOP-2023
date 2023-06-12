public class BlueCard extends Card {
	public BlueCard(Double val) {
		super(val);
	}

	@Override
    public Double value() {
        return number + 0.3;
    }

    @Override
    public void printInfo() {
        System.out.println("Kartu Biru: " + number);
    }
}