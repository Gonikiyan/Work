/*
    HW1C - Sum numbers from 1 to 100.
    Author - Abhishek Kumbhar.
    CITE - Class Notes.

*/

#include<iostream>

using namespace std;

int main(){
    int sum=0, gauss_formula=0, n=0;
    cout<<"please enter the number till what number you need the summation:  ";
    cin>>n;
    gauss_formula=((n*(n+1))/2);
    cout<<"Output using formula"<<'\n';
    cout<<gauss_formula<<'\n';
    for(int i=1; i<=n;i++){
        sum=sum+i;
    }
    cout<<"Output using for loop"<<'\n';
    cout<<sum;
}
