#include <iostream>
#include <string>

using namespace std;

int main() {
	string a;
	int sum_f = 0;
	cin >> a;
    for(size_t i = 0; i < a.size(); ++i){
    	if(a[i] == 'f'){
    		sum_f++;
    		if(sum_f==2){
    		  cout << i;
    		}
    	}
    }
    if(sum_f == 0){
    	cout << -2;
    }
    else if(sum_f == 1){
    	cout << -1;
    }
    	return 0;
}
