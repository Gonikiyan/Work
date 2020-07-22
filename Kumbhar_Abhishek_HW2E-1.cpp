/*
    HW2E - Robot Location Estimator.
    Author - Abhishek Kumbhar.
    CITE - Class Notes and google and professor also helped to clear out the pi/2 doubt.

*/

#include<iostream>
#include<cmath>
#include<fstream>


using namespace std;

double polar2Rect(double a, double b, double &x, double &y){
    x = x + (b * cos(a));
    y = y + (b * sin(a));
}

int main(){
    double a=0, b=0, x=0,y=0, pi=3.14159;
    ifstream infile("hw2e.txt");
    while (infile >> a >> b)
    {
    if(a==-1||b==-1){return 0;}
    a = (a * pi)/180;
    a = (pi/2) - a;
    polar2Rect(a,b,x,y);
    cout<<"x="<<"\t"<<x<<"\t"<<"y="<<"\t"<<y<<'\n';
    }
    return 0;
}
