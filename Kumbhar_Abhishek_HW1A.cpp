/*
    HW1A - 3n+1 Conjecture.
    Author - Abhishek Kumbhar.
    CITE - Class Notes.

*/

#include<iostream>

using namespace std;

int main() {
    int x=0;
    cout<<"Please enter a positive integer:";
    cin>>x;

    while(x!=1){
        if(x%2==0)
            x=x/2;
        else
            x=(3*x)+1;
        cout<<x<<'\n';
    }
    return 0;
}
