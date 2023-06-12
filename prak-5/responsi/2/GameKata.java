import java.util.*;

public class GameKata {
    public static void run(String[] tito, String[] wiwid) {
        Map<String, Integer> m1 = new HashMap<String, Integer>();
        Map<String, Integer> m2 = new HashMap<String, Integer>();

        for (String s : tito) {
            Integer freq = m1.get(s);
            m1.put(s, (freq == null) ? 1 : freq + 1);
        }

        for (String s : wiwid) {
            Integer freq = m2.get(s);
            m2.put(s, (freq == null) ? 1 : freq + 1);
        }

        for (String key : m1.keySet()) {
            if (m2.containsKey(key)) {
                System.out.println(key);
            }
        }
    }

    public static void main(String[] args) {
        String[] tito = {"Halo", "Icad", "Halo"};
        String[] wiwid = {"ABC", "Yey", "Icad", "Halo"};

        run(tito, wiwid);
    }
}