#include <iostream>
#include <algorithm>
#include <sstream>

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
    int naibdelit(int a, int b){
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

bool operator == (Rational lhs,Rational rhs){
	if((lhs.Numerator()==rhs.Numerator())&&(lhs.Denominator()==rhs.Denominator())){
		return true;
	}else{
		return false;
	}
}

Rational operator + (Rational lhs,Rational rhs){
	int a=(lhs.Numerator()*rhs.Denominator())+(rhs.Numerator()*lhs.Denominator());
	int b=lhs.Denominator()*rhs.Denominator();
	return Rational(a,b);
}

Rational operator - (Rational lhs,Rational rhs){
	int a=(lhs.Numerator()*rhs.Denominator())-(rhs.Numerator()*lhs.Denominator());
	int b=lhs.Denominator()*rhs.Denominator();
	return Rational(a,b);
}

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
