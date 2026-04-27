package CH07;

interface Vehicle{
    void start();

    default void stop(){
        System.out.println("정지하고 있습니다.");
    }
}

class Bicycle implements Vehicle{
    @Override
    public void start(){
        System.out.println("자전거가 출발하고 있습니다.");
    }
}

class Car implements Vehicle{
    @Override
    public void start(){
        System.out.println("자동차가 출발하고 있습니다.");
    }
}

public class DefaultMethodTest {
    public static void main(String[] args){
        Vehicle car = new Car();
        car.start();
        car.stop();

        Vehicle bicycle = new Bicycle();
        bicycle.start();
        bicycle.stop();
    }
}
