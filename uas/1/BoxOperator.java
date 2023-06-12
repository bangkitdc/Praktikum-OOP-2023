import java.util.ArrayList;
import java.util.List;
import java.lang.reflect.*;

public class BoxOperator {
    public static <T> List<T> getContents(Box<?> box, Class<T> type) {
        List<T> result = new ArrayList<>();

        try {
            Class<? extends Object> cls = box.getClass();
            Method m = cls.getDeclaredMethod("getContents");
            m.setAccessible(true);

            List<?> contents = new ArrayList<>();
            contents = (List) m.invoke(box);

            for (Object item : contents) {
                if (type.isInstance(item)) {
                    result.add(type.cast(item));
                }
            }
        } catch (Exception e){
            System.out.println(e.getMessage());
        }

        return result;
    }

    // public static void main(String[] args) {
    //     List<Object> l1 = new ArrayList<Object>();
    //     l1.add(1);
    //     l1.add(3.4f);
    //     l1.add(true);
    //     l1.add('c');

    //     Box<Object> b = new Box(l1);

    //     List<Character> l = BoxOperator.getContents(b, Character.class);
    //     System.out.println(l.toString());
    // }
}