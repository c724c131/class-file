import java.util.*;
public class problem1 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int x1, y1, w1, h1;
        int x2, y2, w2, h2;
        System.out.print("사각형 A의 좌상단 좌표 (x1, y1), 너비, 높이 : ");
        x1 = sc.nextInt();
        y1 = sc.nextInt();
        w1 = sc.nextInt();
        h1 = sc.nextInt();
        System.out.print("사각형 A의 좌상단 좌표 (x2, y2), 너비, 높이 : ");
        x2 = sc.nextInt();
        y2 = sc.nextInt();
        w2 = sc.nextInt();
        h2 = sc.nextInt();

        if(((x1 + w1) > x2) && ((y1 - h1) < y2)){
            System.out.println("사각형이 겹칩니다.");
        }
        else if(((x2 + w2) > x1) && ((y2 - h2) < y1)){
            System.out.println("사각형이 겹칩니다.");
        }
        else{
            System.out.println("사각형이 겹치지 않습니다.");
        }
    }
}
