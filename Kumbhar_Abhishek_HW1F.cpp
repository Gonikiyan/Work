/*
    HW1F - Mystery Sum.
    Author - Abhishek Kumbhar.
    CITE - Class Notes.

*/

#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double n=0, x=0;
    float sum1=0.0000000, result1=0.0000000, sum2=0.0000000, result2=0.0000000,  sum3=0.0000000, result3=0.0000000;
    cout<<"Please enter a positive integer:";
    cin>>x;

    for(double i=1; i<=x; i++){
        sum1= sum1 + (1/(i*i));
        }
    result1=sqrt(6*sum1);
    cout<<"result1="<<result1<<'\n';

    cout<<"Please enter a larger positive integer:";
    cin>>n;
    // The first forward loop for that 1/n^2 from 1 to n.
    for(double i=1; i<=n; i++){
        sum2= sum2 + (1/(i*i));
        }
    result2=sqrt(6*sum2);
    cout<<"result2="<<result2<<'\n';

    // Second loop for calculating it backwards from n to 1.
    for(double i=n; i>0; i--){
        sum3= sum3 + (1/(i*i));
        }
    result3=sqrt(6*sum3);
    cout<<"result3="<<result3<<'\n';
}
