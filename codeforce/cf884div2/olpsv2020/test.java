// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.Scanner;

public class Circle {
    public double radius;
    double PI = 3.1415926534; 
    
    public Circle(double radius) {
        this.radius = radius;
    }
    
    public double GetRadius () {
        return this.radius;
    }
    
    public double GetArea() {
        return this.radius * this.radius * PI;
    }
    
    public double GetCircumfrerence() {
        return 2 * this.radius * PI;
    }
    
    public double GetDiameter() {
        return this.radius * 2;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double r = scanner.nextDouble();
        Circle circle = new Circle(r);
        System.out.println(circle.GetArea());
    }
}