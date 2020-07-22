/*
    HW2B - Prime.
    Author - Abhishek Kumbhar.

*/

#include<iostream>
#include<cmath>
using namespace std;

void isPrime(long x){
    if(x<=0){
        cout<<"Invalid number";
        return;
    }

    if(x==1){
        cout<<"Neither prime nor composite";
        return;
    }

    if(x==2){
        cout<<"The number"<<" "<<x<<" "<<"is prime"<<'\n';
        return;
    }
    if(x%2==0){
        cout<<"The number"<<" "<<x<<" "<<"is not prime"<<'\n';
        return;
        }
    for(int i=3; i<sqrt(x); i= i+2){
            if(x%i==0){
                cout<<"The number"<<" "<<x<<" "<<"is not prime"<<'\n';
                return;
            }
    }
    cout<<"The number"<<" "<<x<<" "<<"is prime"<<'\n';
    return;
}



int main(){
    long x;
    cout<<"Please enter a positive integer :";
    cin>>x;
    isPrime(x);

}
