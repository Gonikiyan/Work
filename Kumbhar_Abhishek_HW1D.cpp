/*
    HW1D - Sum Reciprocals.
    Author - Abhishek Kumbhar.
    CITE - Class Notes.

*/

#include<iostream>

using namespace std;

int main(){
    float sum1F=0.000, sum2F=0.000, x=0.000;
    double sum1D=0.000, sum2D=0.000, y=0.000;

    for(int i=1.000; i<=100; i++){
        sum1F= sum1F + (1/float(i));
        sum1D= sum1D + (1/double(i));
        }

    for(int i=100; i>0; i--){
        sum2F= sum2F + (1/float(i));
        sum2D= sum2D + (1/double(i));
        }
    cout<<"sum1F="<<sum1F<<'\n'<<"sum2F="<<sum2F<<'\n'<<"sum1D="<<sum1D<<'\n'<<"sum2D="<<sum2D<<'\n';
    x=sum1F - sum2F;
    y=sum1D - sum2D;
    cout<<"sum1F-sum2F="<<x<<'\n'<<"sum1D-sum2D="<<y;
}
