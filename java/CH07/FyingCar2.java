package CH07;

import java.io.Flushable;

class Car{
    void drive(){
        System.out.println("도로를 달리고 있습니다.");
    }

    void stop(){
        System.out.println("차량이 정지하였습니다.");
    }
}

interface Airplane{
    void fly();
}

public class FyingCar2 extends Car implements Airplane {
    @Override
    public void fly(){
        System.out.println("하늘을 날고 있습니다.");
    }

    public static void main(String[] args){
        FyingCar2 myFlyingCar = new FyingCar2();
        // Car 클래스의 메소드 호출
        myFlyingCar.drive();
        myFlyingCar.stop();

        myFlyingCar.fly();
    }
}
