/*
    HW4A - Vec3d.
    Author - Abhishek Kumbhar.
    CITE - Class Notes and google.

*/

#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>


using namespace std;

class Vec3d{
private:

    double x,y,z;

public:

    Vec3d(double a, double b, double c):x(a),y(b),z(c){}

    Vec3d():x(0),y(0),z(0){}

    Vec3d(double a, double b):x(a),y(b),z(z=0){}

    Vec3d(double a):x(a),y(y=0),z(z=0){}

    void print() const {
    cout<<"("<<this->x<<","<<this->y<<","<<this->z<<")"<<endl;
    }

    friend ostream& operator <<(ostream& s, const Vec3d& f);

    Vec3d operator +(Vec3d v)const{
    return Vec3d(x+v.x, y+v.y, z+v.z);
    }

    Vec3d operator -(Vec3d v)const{
    return Vec3d(x-v.x, y-v.y, z-v.z);
    }

    Vec3d operator -()const{
    return Vec3d(-x, -y, -z);
    }

    friend double dot(Vec3d v, Vec3d w);

    double dot(Vec3d v)const{
    return ((x*(v.x))+(y*(v.y))+(z*(v.z)));
    }

    double mag()const{
    return (pow((pow(x,2)+(pow(y,2))+(pow(z,2))),0.5));
    }

    double magSq()const{
    return (pow(x,2)+pow(y,2)+ pow(z,2));
    }

    double dist(Vec3d f)const{
    Vec3d r((x-f.x),(y-f.y),(z-f.z));
    return r.mag();
    }

    };

ostream& operator <<(ostream& s, const Vec3d& f) {
    s<<"("<<f.x<<","<<f.y<<","<<f.z<<")"<<endl;
    return s;
    }

    double dot(Vec3d v, Vec3d w){
    return ((v.x)*(w.x))+((v.y)*(w.y))+((v.z)*(w.z));
    }


int main() {
	// Main() Section 1
	const Vec3d a(1.0,2.5,3.5); // double precision!
	const Vec3d b(2.0);         //(2,0,0)
	const Vec3d c(2.0,3.5);     //(2,3.5,0)
	const Vec3d d;              //(0,0,0)

	// Main() Section 2
	const Vec3d e = a + d;
	const Vec3d f = c - b;
	const Vec3d g = -e;

	// Main() Section 3
	double r = dot(e, f); // regular function  e.x*f.x + e.y*f.y + e.z*f.z
	double s = e.dot(f); // method

	// Main() Section 4
	double x = e.mag(); // square root of sum of square
	double y = e.magSq(); // sum of square
	double z = e.dist(f); // sqrt or sum of square of diff

	// Main() Section 5
	cout << "a: " << a << '\n';
	cout << "b: " << b << '\n';
	cout << "c: " << c << '\n';
	cout << "d: " << d << '\n';
	cout << "e: " << e << '\n';
	cout << "f: " << f << '\n';
	cout << "g: " << g << '\n';
	cout << "r: " << r << '\n';
	cout << "s: " << s << '\n';
	cout << "x: " << x << '\n';
	cout << "y: " << y << '\n';
	cout << "z: " << z << '\n';

}
