import java.util.*;

public class ElectronicProduct extends Product {
	private String warrantyPeriod;

	public ElectronicProduct(Integer i, String n, Integer p, String d, String w) {
		super(i, n, p, d);
		warrantyPeriod = w;	
	}

	public String getWarrantyPeriod() {
		return warrantyPeriod;
	}

	public String getInfo() {
		return String.format("%d: %s - %d - %s - %s", id, name, price, warrantyPeriod, description);
	}
}