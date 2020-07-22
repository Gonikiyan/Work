/*
    HW2C - Multiple Prime.
    Author - Abhishek Kumbhar.

*/

#include<iostream>
#include<cmath>
using namespace std;

void isPrime(long x, long y){
    long count=0, xx=0,yy=0;
    xx=x;
    yy=y;
    if(x<0||y<0){
        cout<<"Invalid range";
        return;
    }
    if(x<=1){
            x=2;
    }
    for(int i=x; i<=y; i++){
        int z=0;
        for(int j=2; j<i; j++){
            if(i%j==0){
                z=z+1;
            }
        }
        if(z==0){
            count=count+1;
            cout<<i<<"\t";
        }
    }
    cout<<"There are"<<" "<<count<<" "<<"prime numbers in range"<<" "<<"["<<xx<<","<<yy<<"]";
}



int main(){
    long x=0,y=0,temp=0;
    cout<<"Please enter lower range value :";
    cin>>x;
    cout<<"Please enter higher range value :";
    cin>>y;
    if(y<x){
        temp=x;
        x=y;
        y=temp;
    }
    isPrime(x,y);

}
