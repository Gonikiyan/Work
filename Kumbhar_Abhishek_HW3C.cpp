/*
    HW3B - Array Statistics.
    Author - Abhishek Kumbhar.
    CITE - Class Notes and google.

*/

#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>


using namespace std;


int main(){
    int rows=0, cols=0;
    double x=0, row_sum=0, col_sum=0, total_sum=0;
    ifstream infile("3C.txt");
    infile >> rows;
    infile >> cols;
    cout<<"No. of rows = "<<rows<<endl;
    cout<<"No. of columns = "<<cols<<endl;

    double A[rows][cols],B[rows+1][cols+1];
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            infile >> x;
            A[i][j]=x;

        }
        cout<<endl;

    }

    for(int i=0; i<rows; i++){
            for(int j=0;j<cols+1; j++){
                if(j<cols){
                B[i][j]=A[i][j];
                row_sum += A[i][j];
                B[i][cols]=row_sum;
                cout<<B[i][j]<<" ";
                }
                else{
                    cout<<"rowsum = "<<B[i][j]<<" ";
                }

            }
            cout<<endl;
            total_sum+=row_sum;
            row_sum=0;

        }

    for(int i=0; i<cols; i++){
        for(int j=0;j<rows; j++){
            col_sum += A[j][i];
            }
            cout<<col_sum<<" ";
            col_sum=0;
        }
    cout<<"toatlsum= "<<total_sum<<endl;


    return 0;
}
