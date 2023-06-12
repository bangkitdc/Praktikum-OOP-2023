import java.util.*;

public class FoodProduct extends Product {
	private String expiryDate;

	public FoodProduct(Integer i, String n, Integer p, String d, String exp) {
		super(i, n, p, d);
		expiryDate = exp;
	}

	public String getExpiryDate() {
		return expiryDate;
	}

	public String getInfo() {
		return String.format("%d: %s - %d - %s - %s", id, name, price, expiryDate, description);
	}
}