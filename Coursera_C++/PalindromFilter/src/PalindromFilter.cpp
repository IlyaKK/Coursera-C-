#include <iostream>
#include <vector>
#include <string>
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


vector<string> PalindromFilter(vector<string> words,int minLength){
	vector<string> palindroms;
	for(string n:words){
		if(IsPalindrom(n) && n.size() >= minLength){
			palindroms.push_back(n);
		}
	}
	return palindroms;
}

int main(){
	vector<string> words = {"abacaba","aba"};
	int minLength = 5;
	for(string u:PalindromFilter(words, minLength)){
		cout << u;
	}
}
