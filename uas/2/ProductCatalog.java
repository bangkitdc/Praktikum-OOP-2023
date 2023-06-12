import java.util.*;

public class ProductCatalog implements ProductManagement {
	private List<Product> productList;

	public ProductCatalog(List<Product> l) {
		productList = l;
	}

	public void addProduct(Product p) {
		productList.add(p);
	}

	public Product removeProduct(Integer id) {
		for (Product p : productList) {
			if (p.getId().equals(id)) {
				Product ret = p;
				productList.remove(p);
				return ret;
			}
		}

		return null;
	}

	public void updateProduct(Integer id, String name, Integer price, String description) {
		for (Product p : productList) {
			if (p.getId().equals(id)) {
				p.setName(name);
				p.setPrice(price);
				p.setDescription(description);
				return;
			}
		}
		System.out.println("Produk dengan id " + id + " tidak ditemukan");
	}

	public List<Product> getAllProduct() {
		return productList;
	}

	public Product getProduct(Integer id) {
		for (Product p : productList) {
			if (p.getId().equals(id)) {
				return p;
			}
		}

		return null;
	}

	// public static void main(String[] args) {
	// 	List<Product> l = new ArrayList<>();
	// 	ProductCatalog pc = new ProductCatalog(l);

	// 	FoodProduct fp = new FoodProduct(1, "test", 5, "date", "exp");
	// 	pc.addProduct(fp);

	// 	Product p = pc.getProduct(1);

	// 	List<Product> l1 = pc.getAllProduct();
	// 	System.out.println(l1.toString());

	// 	pc.updateProduct(2, "halo", 10, "date2");

	// 	// Product del = pc.removeProduct(1);

	// 	// System.out.println(del.toString());

	// 	// List<Product> ll = pc.getAllProduct();
	// 	// System.out.println(ll.toString());
	// }
}