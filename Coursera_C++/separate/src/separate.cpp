#include <iostream>
using namespace std;

int main() {
	int a,b;
	cin >> a >> b;
	if ( b==0 || a > 1000000 || b > 1000000 ){
		cout << "Impossible";
	}
	else{
		cout << a/b;
	}
	return 0;
}
