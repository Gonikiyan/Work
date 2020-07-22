/*
    HW2A - Windchill.
    Author - Abhishek Kumbhar.
    CITE - google for matrix.

*/

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
    float A[20][20];

    for(int i=0,speed=5; speed<=60; i++,speed=speed+5){ // wind speed V=i
        for(int j=0, temp=40; temp>=-45; j++, temp=temp-5){ // Temperature T=j
            A[i][j] = 35.74 + 0.6215*(temp*1.0) - 35.75*(pow(speed,0.16)) + 0.4275*temp*(pow(speed,0.16));
            cout<<A[i][j]<<setprecision(2)<<"\t";
        }
        cout<<'\n';
    }
    return 0;
}
