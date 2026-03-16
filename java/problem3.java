import java.util.*;
public class problem3 {
    public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int x1,y1,x2,y2,x,y;
    System.out.print("사각형의 좌하단(x1, y1) 좌표를 입력하세요 : ");
    x1 = sc.nextInt();
    y1 = sc.nextInt();
    System.out.print("사각형의 우상단(x2, y2) 좌표를 입력하세요 : ");
    x2 = sc.nextInt();
    y2 = sc.nextInt();
    System.out.print("점의 좌표(x, y)를 입력하세요 : ");
    x = sc.nextInt();
    y = sc.nextInt();

    if((x>x2) || (y>y2) || (x<x1) || (y<y1)){
        System.out.print("점("+x+"," +y+")는 사각형 밖에 있습니다");
    }
    else if((x2>x && x>x1) && (y2>y && y>y1)){
        System.out.print("점("+x+"," +y+")는 사각형 안에 있습니다");
    }
    else{
        System.out.print("점("+x+"," +y+")는 사각형의 경계에 있습니다");
    }
    }
}
