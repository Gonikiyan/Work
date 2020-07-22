/*
    HW2D - String Manipulation.
    Author - Abhishek Kumbhar.
    CITE - Class Notes and google and banish deep ojha.

*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string removeVowels(string &A){
        string B="";
        /*A.erase(remove(A.begin(), A.end(), 'a'), A.end());
        A.erase(remove(A.begin(), A.end(), 'e'), A.end());
        A.erase(remove(A.begin(), A.end(), 'i'), A.end());
        A.erase(remove(A.begin(), A.end(), 'o'), A.end());
        A.erase(remove(A.begin(), A.end(), 'u'), A.end());
        A.erase(remove(A.begin(), A.end(), 'A'), A.end());
        A.erase(remove(A.begin(), A.end(), 'E'), A.end());
        A.erase(remove(A.begin(), A.end(), 'I'), A.end());
        A.erase(remove(A.begin(), A.end(), 'O'), A.end());
        A.erase(remove(A.begin(), A.end(), 'U'), A.end());*/
        for(int i=0; i< A.size(); i++){
            if(A[i]=='a'|| A[i]=='e'|| A[i]=='i' || A[i]=='o' || A[i]=='u' || A[i]=='A' || A[i]=='E' || A[i]=='I' || A[i]=='O' || A[i]=='U')
                continue;
            B=B.append(1,A[i]);
        }
        return B;
}

int main(){
    int c=0;
    string A="",B="";
    cout<<"Please enter a string of characters = ";
    getline(cin,A);
    /*for(int i=0; A[i]; i++){
        c++;
    }*/
    //cout << A.size()<< endl;
    cout<<"The string backwards is ="<<" ";
    for(int i=(A.size()-1); i>=0; i--){
        B=B.append(1,A[i]);
    }
    cout<<B<<endl;

    if(A.compare(B)==0){
        cout<<"The strings is palindrome"<<endl;
    }
    else{
        cout<<"The strings is not palindrome"<<endl;
    }

    A=removeVowels(A);
    cout<<"The string without vowels is :"<<" ";
    cout<<A<<endl;
    return 0;
}
