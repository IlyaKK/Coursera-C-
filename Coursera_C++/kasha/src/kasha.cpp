#include <iostream>
#include <set>
using namespace std;

int main() {
	set<int> k1;
	set<int> k2;
    int i=0;
    int j=1;
    k1.insert(i);
    k1.insert(j);
    k2.insert(j);
    k2.insert(i);
    for(auto h:k1){
    	cout<<h<<" ";
    }
    for(auto q:k2){
        	cout<<q<<" ";
        }
	return 0;
}
