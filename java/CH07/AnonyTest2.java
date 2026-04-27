package CH07;

abstract class Animal{
    abstract void sound();
}

public class AnonyTest2 {
    public static void main(String[] args){
        Animal dog = new Animal(){
            @Override
            void sound() {
                System.out.println("DOg bark");
            }
        };
        dog.sound();
    }
}
