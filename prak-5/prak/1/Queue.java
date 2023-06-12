import java.util.ArrayList;

public class Queue<T> {

    private ArrayList<T> data;

    private int lastElmIdx, size;

    private final static int DEFAULT_QUEUE_SIZE = 500;


  //Instantiate dengan size default

    public Queue() {
        // this.data = new ArrayList<>(DEFAULT_QUEUE_SIZE);
        this.data = new ArrayList<>();
        this.size = DEFAULT_QUEUE_SIZE;
        this.lastElmIdx = -1;
    }

  //Instantiate dengan size = n

    public Queue(int n) {
        this.data = new ArrayList<>();
        this.size = n;
        this.lastElmIdx = -1;
    }

  //Copy queue

    public Queue(final Queue<T> q) {
        this.data = new ArrayList<>();
        this.size = q.size;
        this.lastElmIdx = q.lastElmIdx;

        for (T x: q.data) {
            this.data.add(x);
        }
    }

    public void push(T t) {
        if (!isFull()) {
            this.data.add(t);
            this.lastElmIdx ++;
        }
    }

    public T pop() {
        if (!isEmpty()) {
            T res = this.data.get(0);
            this.data.remove(0);
            this.lastElmIdx --;

            return res;
        }
        return null;
    }

    public boolean isEmpty() {
        return (this.lastElmIdx == -1);
    }

    public boolean isFull() {
        return (this.data.size() == this.size);
    }

    // public static void main(String[] args) {
    //     Queue q = new Queue<Integer>();

    //     System.out.println(q.isEmpty());
    // }
}