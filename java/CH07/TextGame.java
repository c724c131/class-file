package CH07;

import java.util.Scanner;

abstract class Sprite {
    int x = 3, y = 3;
    abstract void move(char c);
}
class Main extends Sprite {
    void move(char c) {
        if (c == 'h') --x;
        else if (c == 'j') --y;
        else if (c == 'k') ++y;
        else if (c == 'l') ++x;
    }
}
class Monster extends Sprite {
    public Monster() {
        x = y = 7;
    }
    void move(char c){
        x += (Math.random()-0.5)>0? 1: -1;
        y += (Math.random()-0.5)>0? 1: -1;
    }
}

public class TextGame {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        char[][] map = {
                {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                {'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                {'#',' ',' ',' ','G',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
                {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
        };
        Main mine = new Main();
        Monster mon = new Monster();
        while(true){
            map[mine.y][mine.x] = '@';
            map[mon.y][mon.x] = 'M';
            for (int i=0;i<10;i++){
                for(int j=0;j<18;j++){
                    System.out.print(map[i][j]);
                }
                System.out.println();
            }
            System.out.print("왼쪽(h) 위쪽(j) 아래쪽(k) 오른쪽(l) : ");
            map[mine.y][mine.x] = ' ';
            map[mon.y][mon.x] = ' ';
            char c = sc.next().charAt(0);
            mine.move(c);
            mon.move(c);

        }
    }
}
