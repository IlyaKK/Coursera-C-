#include <iostream>
#include <algorithm>
using namespace std;

class Rational {
public:
    Rational() {
      num=0;
      den=1;
    }
    Rational(int numerator, int denominator) {
      if(numerator<0){
    	  if(denominator<0){
             numerator=abs(numerator);
             denominator=abs(denominator);
    	  }
    	  else{
    		  numerator=abs(numerator);
    		  k=-1;
    	  }
      }else if(denominator<0){
    	  denominator=abs(denominator);
    	  k=-1;
      }
      if(numerator==0)denominator=1;
      num=numerator/naibdelit(numerator,denominator);
      den=denominator/naibdelit(numerator,denominator);
    }

    int Numerator() const {
      return k*num;
    }

    int Denominator() const {
      return den;
    }

private:
    int num,den;
    int k=1;
    int naibdelit(int n, int d){
    	int a=n;
    	int b=d;
    		while( a>0 && b>0 ){
    			if(a>b){
    				a = a%b;
    			}
    			else{
    				b = b%a;
    			}
    		}
    		return a+b;
    }
};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
