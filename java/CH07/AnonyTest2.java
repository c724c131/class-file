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

///애니멀 클래스 생성자 초기화 super() 사용
