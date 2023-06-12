public class RedCard extends Card {
	public RedCard(Double val) {
		super(val);
	}

	@Override
    public Double value() {
        return number + 0.9;
    }

    @Override
    public void printInfo() {
        System.out.println("Kartu Merah: " + number);
    }
}