#include <iostream>
#include <exception>
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
      if(denominator==0){
    	  throw invalid_argument("zero denominator");
      }
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

bool operator == (const Rational& lhs, const Rational& rhs) {
  return lhs.Numerator() == rhs.Numerator() &&
      lhs.Denominator() == rhs.Denominator();
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Numerator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
  if(rhs.Numerator()==0){
	  throw domain_error("division by zero");
  }
  return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument& e) {
    	cout << e.what() << endl;
    }

    try {
    	auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error& h) {
    	cout << h.what() << endl;
    }

    cout << "OK" << endl;
    return 0;
}
