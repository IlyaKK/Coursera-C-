#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
    auto n = v;
    int l=n.size()-1;
    for (int i = 0; i < n.size() / 2; ++i) {
        auto t = n[i];
        n[i] = n[l - i];
        n[l - i] = t;
    }
    return n;
}

int main() {
	vector<int> numbers = {1, 5, 3, 4, 2};
    for(int j:Reversed(numbers)){
       cout<<" "<<j;
    }
	return 0;
}
