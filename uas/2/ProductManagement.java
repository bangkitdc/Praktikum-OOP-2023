import java.util.*;

interface ProductManagement {
	public void addProduct(Product p);

	public Product removeProduct(Integer id);

	public void updateProduct(Integer id, String name, Integer price, String description);

	public List<Product> getAllProduct();

	public Product getProduct(Integer id);
}