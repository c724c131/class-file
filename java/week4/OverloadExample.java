public class OverloadExample {
    int add(int x, int y) {
        return x + y;
    }
    int add(int x, int y, int z) {
        return x + y + z;
    }
    int add(int w, int x, int y, int z) {
        return w + x + y + z;
    }
    public static void main(String[] args) {
        OverloadExample obj = new OverloadExample();
// 다양한 오버로딩된 메소드 호출
        System.out.println(" "+obj.add(10, 20));
        System.out.println(" "+obj.add(10, 20, 30));
        System.out.println(" "+obj.add(10, 20, 30, 40));
    }
}
//메소드 구분은 오직 매개변수를 보고 결정
