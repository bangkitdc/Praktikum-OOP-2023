import java.util.*;

class Pasukan {
	private List<Integer> list;
	private int n;

	public Pasukan(List<Integer> list, int n) {
		this.list = list;
		this.n = n;
	}

	public void reset() {
		list.clear();
		for (int i = 0; i < n; i ++) {
			list.add(0);
		}
	}

	public long get(int idx) {
		reset();
		Util t = new Util();
		long start = t.getTime();

		Integer i = list.get(idx);

		long finish = t.getTime();

		return (finish - start);
	}

	public long del(int idx, int t) {
		reset();
		Util s = new Util();
		long start = s.getTime();

		for (int i = 0; i < t; i ++) {
			list.remove(idx);
		}

		long finish = s.getTime();

		return (finish - start);
	}
}