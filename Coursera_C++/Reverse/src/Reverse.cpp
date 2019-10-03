#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Reverse(vector<int>& v){
	vector<int> m=v;
	int l=m.size()-1;
	for(int k:m){
	   v[l]=k;
	   l--;
	}
}

int main() {
	vector<int> numbers = {1, 5, 3, 4, 2};
	Reverse(numbers);
	return 0;
}
