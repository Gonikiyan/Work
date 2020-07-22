/*
    HW4C - Shapes.
    Author - Abhishek Kumbhar.
    CITE - Class Notes and google.

*/

#include <iostream>
#include <cmath>
using namespace std;

class Shapes{
private:
    double x,y;

public:
    Shapes(double x, double y):x(x),y(y){}

    //virtual double area()const=0;
};

class Rect : public Shapes{
private:
    double width,height;

public:
    Rect(double x, double y, double width, double height):Shapes(x,y),width(width),height(height){}

    double area()const{
    return width*height;
    }
};

class Circle : public Shapes{
private:
    double Radius;

public:
    Circle(double x, double y, double Radius):Shapes(x,y),Radius(Radius){}

    double area()const{
    return M_PI*pow(Radius,2);
    }
};

class Line : public Shapes{
private:
    double startpoint, endpoint;

public:
    Line(double x, double y, double startpoint, double endpoint):Shapes(x,y),startpoint(startpoint),endpoint(endpoint){}

    double area()const{
    return 0;
    }
};

int main() {
	Rect r1(100, 50, 20, 40);	// Rect(x,y, width, height)
	cout << r1.area() << '\n';
  Circle c1(400, 300, 50); // Circle(x,y,radius)
  cout << c1.area() << '\n'; // area should be pi * radius squared
  Line L1(0,0, 300, 400);
  cout << L1.area() << '\n'; // area should be 0
#if 0
	Shape* shapes[6];
	shapes[0] = &r1;
	shapes[1] = &c1;
	shapes[2] = &L1;
	for (int i = 0; i < 2; i++)
		cout << shapes[i]->area() << '\n';
	for (auto s : shapes)
		if (s != nullptr)
			cout << s->area() << '\n';

#endif
}
