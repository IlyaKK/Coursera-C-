#include <iostream>
using namespace std;

int main(){
    double N,A,B,X,Y,discount;
    cin>>N>>A>>B>>X>>Y;
    if (N>A && N<=B){
        discount=((100-X)*N)/100;
        cout<<discount;
    }
    else if (N>B){
        discount=((100-Y)*N)/100;
        cout<<discount;
    }
    else{
        cout<<N;
    }
    return 0;
}
