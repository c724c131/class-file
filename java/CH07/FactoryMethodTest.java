package CH07;

import java.awt.*;

interface Shape{
    void draw();

    static Shape create(String type){
        switch (type){
            case "circle":
                return new Circle();
            case "rectangle":
                return new Rectangle();
            default:
                throw new IllegalArgumentException("Unknown shape type");
        }
    }
}

class Circle implements Shape{
    @Override
    public void draw(){
        System.out.println("원을 그립니다.");
    }
}

class Rectangle implements Shape{
    @Override
    public void draw(){
        System.out.println("사각형을 그립니다.");
    }
}

public class FactoryMethodTest {
    public static void main(String[] args){
        Shape circle = Shape.create("circle");
        circle.draw();
        Shape rectangle = Shape.create("rectangle");
        rectangle.draw();
    }
}
