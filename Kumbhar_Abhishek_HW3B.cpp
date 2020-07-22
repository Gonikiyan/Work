/*
    HW3B - Array Statistics.
    Author - Abhishek Kumbhar.
    CITE - Class Notes and google and banish deep ojha for understanding the vector functions.

*/

#include<iostream>
#include<vector>
#include<fstream>
#include<cmath>


using namespace std;


int main(){
    vector<double> X;

    ifstream infile("3B.txt");

    double i, max_no=-10000000, min_no=+10000000, add=0, mean=0, squares=0, var=0;

    while(infile >> i){
        X.push_back(i);
        //max_no=X[0];
        //min_no=X[0];
        /*if(X[i]>=max_no){max_no=X[i];}
        if(X[i]<=min_no){min_no=X[i];}
        add = add + X[i];
        squares = squares + pow(X[i],2);*/
        if (i>max_no)
            max_no=i;
        if (i<min_no)
            min_no=i;
        add+=i;
        squares+=i*i;
    }

    int n=X.size();
    cout<<"Elements ="<<" "<<n<<endl;

    /*for(int i=0; i<n;i++){
        if(X[i]>=max_no){max_no=X[i];}
        if(X[i]<=min_no){min_no=X[i];}
        add = add + X[i];
        squares = squares + pow(X[i],2);

    }*/

    cout<<"Max ="<<" "<<max_no<<endl;
    cout<<"Min ="<<" "<<min_no<<endl;
    mean = (add/X.size());
    cout<<"Mean = "<<" "<<mean<<endl;
    var = (squares - (n*pow(mean,2)))/n;
    cout<<"Variance = "<<" "<<var<<endl;
    infile.close();
    return 0;
}
