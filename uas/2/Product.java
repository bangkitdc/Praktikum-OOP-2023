import java.util.*;

public abstract class Product {
	protected Integer id;
	protected String name;
	protected Integer price;
	protected String description;

	public Product(Integer i, String n, Integer p, String d) {
		id = i;
		name = n;
		price = p;
		description = d;
	}

	public void setId(Integer i) {
		id = i;
	}

	public void setName(String n) {
		name = n;
	}

	public void setPrice(Integer p) {
		price = p;
	}

	public void setDescription(String d) {
		description = d;
	}


	public Integer getId() {
		return id;
	}

	public String getName() {
		return name;
	}

	public Integer getPrice() {
		return price;
	}

	public String getDescription() {
		return description;
	}

	abstract public String getInfo();
}