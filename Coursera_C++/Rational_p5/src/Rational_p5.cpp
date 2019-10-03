#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
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

bool operator == (const Rational& lhs,const Rational& rhs){
	if((lhs.Numerator()==rhs.Numerator())&&(lhs.Denominator()==rhs.Denominator())){
		return true;
	}else{
		return false;
	}
}

bool operator < (const Rational& lhs,const Rational& rhs){
	double a,b,c,d;
	a=lhs.Numerator();
	b=lhs.Denominator();
	c=rhs.Numerator();
	d=rhs.Denominator();
	if((a/b)<(c/d)){
		return true;
	}else{
		return false;
	}
}

bool operator > (const Rational& lhs,const Rational& rhs){
	double a,b,c,d;
	a=lhs.Numerator();
	b=lhs.Denominator();
	c=rhs.Numerator();
	d=rhs.Denominator();
	if((a/b)>(c/d)){
		return true;
	}else{
		return false;
	}
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
