  
import java.util.*;

abstract class Shape{
    
    float l;
    float b;
    float r;
    final float pi = 3.14f;
    
    abstract void printArea();
}


class Rectangle extends Shape{
    
    Scanner in = new Scanner(System.in);
    
    
    float l = in.nextFloat();
    float b = in.nextFloat();
    void printArea(){
         System.out.println("RECTANGLE AREA METHOD");
         System.out.println("The area of the rectangle is: " + l*b);
         
    }
   
}

class Triangle extends Shape{
    
     Scanner in = new Scanner(System.in);
    
     float l = in.nextFloat();
     float b = in.nextFloat();
     
     void printArea(){
         System.out.println("TRIANGLE AREA METHOD");
         System.out.println("Area of Triangle is: " + (l*b)/2);
         
     }

}     
    
class Circle extends Shape{
    
     Scanner in = new Scanner(System.in);
  
     float r = in.nextFloat();
     
     void printArea(){
         System.out.println("CIRCLE AREA METHOD");
         System.out.println("Area of Circle is: " + pi*r*r);
         
     }

}         
    
    
public class Main{
    
    public static void main(String args[]){
        
        System.out.println("Enter dimensions for Rectangle: ");
        Rectangle rec = new Rectangle();
        
        System.out.println("Enter dimensions for Triangle: ");
        Triangle tri = new Triangle();
        
        System.out.println("Enter dimensions for Circle: ");
        Circle cir = new Circle();
        
        rec.printArea();
        
        tri.printArea();
        
        cir.printArea();
    }
}    
