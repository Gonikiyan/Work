/*
    HW1B - Convergence of n-gons.
    Author - Abhishek Kumbhar.
    CITE -  my friend Banish Deep Ojha helped me understand that the pattern was not in the radius of the circles but is in angles
            as they are getting bisected. Also type casting is needed for you get the same angle and radius gets very big.
            Googled for knowing the sin takes values in radians not in degrees.

*/

#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double theta=0, radius=1, pi = 3.14259;

    for(int i=3; i<=pow(10,6); i++){
        // for internal angle of regular polygon formula.
        theta=((i-2)*180)/double(i);
        //cout<<"theta:"<<theta<<'\n';
        theta=theta/2;
        // conversion of degree
        theta=pi*(theta/180);
        radius=(radius)/sin(theta);
        //cout<<"i="<<i<<"\t\tradius :"<<radius<<'\n';
        if(i==10 || i==100 || i==1000 || i==10000 || i==100000 || i==1000000){
            cout<<"i="<<i<<"\t\tradius :"<<radius<<'\n';
            cout<<"theta:"<<theta<<'\n';
        }

    }

}
