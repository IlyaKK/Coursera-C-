#include <iostream>
#include <string>
#include <vector>
using namespace std;

void MoveStrings(vector<string>& a, vector<string>& b){
	for(string k:a){
		b.push_back(k);
	}
	a.clear();
}

int main() {
	vector<string> source = {"a", "b", "c"};
	vector<string> destination = {"z"};
	MoveStrings(source, destination);
	for(string l:destination){
		cout<<l;
	}
	for(string m:source){
			cout<<m;
		}
	return 0;
}
