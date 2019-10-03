#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	int q;
	cin >> q;
	set<string> str;
	string k;
	for(int t = 0; t < q; t++){
       cin>>k;
       str.insert(k);
	}
    cout << str.size();
	return 0;
}
