public class Comparator {
    public static boolean isObj1BiggerThanObj2(Calculable c1, Calculable c2){
        return c1.value() > c2.value();
    }

    public static boolean isObj1LowerThanObj2(Calculable c1, Calculable c2){
        return c1.value() < c2.value();
    }

    public static boolean isObj1EqualToObj2(Calculable c1, Calculable c2){
        return c1.value().equals(c2.value());
    }

    // public static void main(String[] args) {
    //     RedCard r = new RedCard(5.0);
    //     YellowCard y = new YellowCard(5.0);

    //     r.printInfo();
    //     y.printInfo();

    //     System.out.println(r.value());
    //     System.out.println(y.value());

    //     System.out.println(isObj1BiggerThanObj2(r, y));
    // }
}