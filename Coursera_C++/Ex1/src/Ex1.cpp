#include <iostream>
#include <set>
#include <vector>


using namespace std;

int main() {
	int n, size_vector, size_set;
	cin >> n;
	vector<int> numbers(n);
	for(auto& k:numbers){
		cin >> k;
	}
	size_vector = numbers.size();
	set<int> numbers1;
	for(const auto& l:numbers){
		numbers1.insert(l);
	}
	size_set = numbers1.size();
	cout << size_vector-size_set;
	return 0;
}
