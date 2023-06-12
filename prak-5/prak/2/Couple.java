import java.util.*;

class Couple<K, V> {
	private K key;
	private V val;

	public Couple (K key, V val) {
		this.key = key;
		this.val = val;
	}

	public K getKey() {
		return key;
	}

	public V getVal() {
		return val;
	}

	public void setKey(K key) {
		this.key = key;
	}

	public void setVal(V val) {
		this.val = val;
	}

	public boolean isEqual(Couple<K, V> c) {
		return (this.getKey().equals(c.getKey()) && this.getVal().equals(c.getVal()));
	}

	public int nearEQ(Couple couple) {
		if (this.isEqual(couple)) {
			return 3;
		}

		if (this.getVal().equals(couple.getVal())) {
			return 2;
		}

		if (this.getKey().equals(couple.getKey())) {
			return 1;
		}

		return 0;
	}

	// public static void main(String[] args) {
	// 	Couple<Integer, Double> c = new Couple<>(1, 2.0);
	// 	Couple<Integer, Double> d = new Couple<>(1, 2.0);

	// 	System.out.println(c.isEqual(d));
	// }
}