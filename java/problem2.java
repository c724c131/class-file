import java.util.*;
public class problem2 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int h, k ,r;
        int x, y;

        System.out.print("원의 중심 (h, k) 좌표와 반지름을 입력하세요 : ");
        h = sc.nextInt();
        k = sc.nextInt();
        r = sc.nextInt();

        System.out.print("점의 죄표 (x,y)를 입력하세요 : ");
        x = sc.nextInt();
        y = sc.nextInt();

        boolean result = (((x - h)^2) + ((y - k)^2) <= (r^2));
        if (result){
            System.out.print(("점 (" + x + ", "+ y + ")는 원 위에 있습니다."));
        }
        else{
            System.out.print(("점 (" + x + ", "+ y + ")는 원 위에 없습니다."));
        }
        sc.close();
    }
}
