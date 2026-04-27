package CH07;

interface RemoteControl {
    void turnOn();
    void turnOff();
}

public class AnonyTest1 {
    public static void main(String[] args){
        RemoteControl obj = new RemoteControl() {
            @Override
            public void turnOn() {
                System.out.println("TV turnOn()");
            }

            @Override
            public void turnOff() {
                System.out.println("TV turnOff()");
            }
        };
        obj.turnOn();
        obj.turnOff();
    }
}
