#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a,b,c;
    cin>>a>>b>>c;
    if (a==0 && b!=0 && c!=0){
        cout<<-c/b;
    }
    else if (b*b-4*a*c>0 && a!=0 && b!=0){
        cout<<(-b-sqrt(b*b-4*a*c))/(2*a)<<" "<<(-b+sqrt(b*b-4*a*c))/(2*a);
    }
    else if (b*b-4*a*c==0 && a!=0 && b!=0 && c!=0){
        cout<<(-b-sqrt(b*b-4*a*c))/(2*a);
    }
    else if (b*b-4*a*c<0 || (a==0 && b==0))
    cout<<" ";
    else if(b == 0 && c == 0)
    cout<<0;
    else if(a == 0 && c == 0)
    cout<<0;
	return 0;
}
