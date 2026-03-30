class Circle {
    public int radius;
    public String color;
    public double getArea() { // 기본 getArea() 메소드
        return 3.14 * radius * radius;
    }
    public double getArea(int r) { // 반지름을 매개변수로 받는 getArea() 메소드
        return 3.14 * r * r;
    }
}

public class CircleTest {
    public static void main(String[] args) {
        Circle obj = new Circle(); // 객체 생성
        obj.radius = 100;
        obj.color = "blue";
        double area1 = obj.getArea(); // 기본 getArea() 메소드 호출
        System.out.println("원의 면적 = " + area1);
        double area2 = obj.getArea(30); // 반지름을 매개변수로 받는 getArea() 메소드 호출
        System.out.println("반지름 30의 원의 면적 = " + area2);
    }
}
