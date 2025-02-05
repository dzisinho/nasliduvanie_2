#include <iostream>

using namespace std;

class Circle {
public:
 
    Circle(double r) : radius(r) {}

    double area() const {
        return 3.141592653589793 * radius * radius;
    }

    double perimeter() const {
        return 2 * 3.141592653589793 * radius;
    }

    double getRadius() const {
        return radius;
    }

private:
    double radius;  
};

class Square {
public:

    Square(double s) : side(s) {}

    double area() const {
        return side * side;
    }

    double perimeter() const {
        return 4 * side;
    }

    double getSide() const {
        return side;
    }

private:
    double side;  
};

class CircleInSquare : public Circle, public Square {
public:
    CircleInSquare(double side) : Square(side), Circle(side / 2) {}

    double getInscribedCircleRadius() const {
        return getSide() / 2;
    }

    double squareArea() const {
        return Square::area();
    }

    double squarePerimeter() const {
        return Square::perimeter();
    }

    double circleArea() const {
        return Circle::area();
    }

    double circlePerimeter() const {
        return Circle::perimeter();
    }
};

int main() {
    CircleInSquare cis(10);

    cout << "Square Area: " << cis.squareArea() << endl;
    cout << "Square Perimeter: " << cis.squarePerimeter() << endl;
    cout << "Circle Area: " << cis.circleArea() << endl;
    cout << "Circle Perimeter: " << cis.circlePerimeter() << endl;
    cout << "Inscribed Circle Radius: " << cis.getInscribedCircleRadius() << endl;

    return 0;
}
