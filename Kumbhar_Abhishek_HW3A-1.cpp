/*
    HW3A - Complex Math.
    Author - Abhishek Kumbhar.
    CITE - Class Notes and google.

*/

#include <iostream>

using namespace std;

class Complex{
  private:
    double real_part=0, imaginary_part=0;   // no initialiozation in private.

  public:
    Complex(double a, double b){
    real_part= a;
    imaginary_part= b;
    }
    void print() const {
        if(imaginary_part>=0){
            cout<<real_part<<" + "<<imaginary_part<<"i"<<endl;
        }
        else
            cout<<real_part<<" - "<<((-1)*imaginary_part)<<"i"<<endl;
    }

    Complex add(Complex v)const{
    return Complex(real_part+v.real_part, imaginary_part+v.imaginary_part);
    }

    friend Complex operator +(Complex r, Complex s){
    return Complex(r.real_part+s.real_part, r.imaginary_part+s.imaginary_part);
    }

    Complex operator -()const{
    return Complex(-real_part, -imaginary_part);
    }

};



int main() {
	const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
	const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
	const Complex c = a + b;   // overload operator + using a friend function
	c.print(); // should print the following to cout: (1.5,2.0)
	// (member syntax).  Should look the same as method add where the name add
	// is replaced by operator +
	const Complex d = a.add(b); // this should be the same as the above except the name
	d.print();
	Complex e = -d; // implement unary - using a member operator. Since it has one parameter which is this should have ZERO PARAMETERS!!!
	e.print();
}
