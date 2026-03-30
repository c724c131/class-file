import java.util.Scanner;
import java.util.Random;

public class problem4 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Random random = new Random();
        int num;
        int cnt = 0;
        int target = random.nextInt(100);
        while (true) {
            System.out.print("정답을 추측하여 보시오 : ");
            num = sc.nextInt();
            if(num < target){
                System.out.println("제시한 정수가 낮습니다");
                cnt++;}
            else if(num > target){
                System.out.println("제시한 정수가 높습니다");
                cnt++;}
            else{
                cnt++;
                break;}
        };

        System.out.print("축하합니다. 시도 횟수 = " + cnt);

    }
}
