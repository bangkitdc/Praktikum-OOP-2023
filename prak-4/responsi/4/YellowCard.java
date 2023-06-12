public class YellowCard extends Card {
	public YellowCard(Double val) {
		super(val);
	}

	@Override
    public Double value() {
        return number + 0.6;
    }

    @Override
    public void printInfo() {
        System.out.println("Kartu Kuning: " + number);
    }
}