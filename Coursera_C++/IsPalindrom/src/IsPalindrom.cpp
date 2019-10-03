#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string n){
	if(n.size()==0){
		return true;
	}
	for(size_t i=0; i < n.size(); ++i){
		if(n[i] == 'A' || n[i] == 'B' || n[i] == 'C' || n[i] == 'D' || n[i] == 'E' || n[i] == 'F' || n[i] == 'G' || n[i] == 'H' || n[i] == 'I' || n[i] == 'J' || n[i] == 'K' || n[i] == 'L' || n[i] == 'M' || n[i] == 'N' || n[i] == 'O' || n[i] == 'P' || n[i] == 'Q' || n[i] == 'R' || n[i] == 'S' || n[i] == 'T' || n[i] == 'U' || n[i] == 'V' || n[i] == 'W' || n[i] == 'X' || n[i] == 'W' || n[i] == 'Z'){
			n[i]=n[i] - 'A' + 'a';
		}
	}

    int long_k=n.size();
	for (auto pal:n) {
	        if (pal != n[long_k - 1]) {
	            return false;
	        }
	        long_k--;
	    }
	return true;
}

int main() {
	string n;
	cin >> n;
	if(IsPalindrom(n) == 1){
		cout << "true";
	}
	else{
		cout<< "false";
	}
	return 0;
}
