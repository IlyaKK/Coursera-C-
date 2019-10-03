#include <iostream>
#include <exception>
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
      if(denominator==0){
    	  throw invalid_argument("Invalid argument");
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

Rational operator + (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Numerator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
  if(rhs.Numerator()==0){
	  throw domain_error("Division by zero");
  }
  return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

istream& operator >> (istream& is, Rational& r) {
  int n, d;
  char c;
  is >> n >> c >> d;
  if (is && c == '/') {
    r = Rational(n, d);
  }
  return is;
}

ostream& operator << (ostream& os, const Rational& r) {
  return os << r.Numerator() << '/' << r.Denominator();
}

int main() {
	string a,c;
	char b;
	cin>>a>>b>>c;
	istringstream input(a+' '+c);
	Rational r1,r2;
	try{
	input >>r1>>r2;
    if(b=='+'){
    	cout<<r1+r2;
    }else if(b=='-'){
    	cout<<r1-r2;
    }else if(b=='*'){
    	cout<<r1*r2;
    }else if(b=='/'){
    	 try {
    	cout<<r1/r2;
    	 }catch(domain_error& h){
    		 cout << h.what() << endl;
    	 }
    }
	}catch(invalid_argument& e){
		cout << e.what() << endl;
	}
    return 0;
}
