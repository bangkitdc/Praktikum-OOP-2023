import java.util.*;

public class FashionProduct extends Product {
	private String size;

	public FashionProduct(Integer i, String n, Integer p, String d, String s) {
		super(i, n, p, d);
		size = s;	
	}

	public String getSize() {
		return size;
	}

	public String getInfo() {
		return String.format("%d: %s - %d - %s - %s", id, name, price, size, description);
	}
}