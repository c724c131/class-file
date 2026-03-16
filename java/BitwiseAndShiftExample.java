public class BitwiseAndShiftExample {
    public static void main(String[] args) {
        int a = 5;
        int b = 3;

        System.out.println("a : " + a + "(" + Integer.toBinaryString(a) + ")");
        System.out.println("b : " + b + "(" + Integer.toBinaryString(b) + ")");

        System.out.println("a & b : " + (a&b) + "(" + Integer.toBinaryString(a&b) + ")");
        System.out.println("a | b : " + (a|b) + "(" + Integer.toBinaryString(a|b) + ")");
        System.out.println("a ^ b : " + (a^b) + "(" + Integer.toBinaryString(a^b) + ")");
        System.out.println("~a : " + (~a) + "(" + Integer.toBinaryString(~a) + ")");
        System.out.println("a << 1 : " + (a << 1) + "(" + Integer.toBinaryString(a << 1) + ")");
        System.out.println("a >> 1 : " + (a >> 1) + "(" + Integer.toBinaryString(a >> 1) + ")");
        System.out.println("a >>> 1 : " + (a >>> 1) + "(" + Integer.toBinaryString(a >>> 1) + ")");
    }
}
