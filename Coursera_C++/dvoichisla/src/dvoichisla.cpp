#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a;
	int i=0;
	int j=0;
	cin>>a;
	vector<int> resh = {a};
	vector<int> ost;
	while(resh[i]>1){
	resh.push_back(resh[i]/2);
	ost.push_back(resh[i]-2*resh[i + 1]);
	i++;
	}
	vector<int> dvoich = {resh[i]};
    for(int j=ost.size()-1; j>=0; j--){
    	dvoich.push_back(ost[j]);
    }
    while(j<dvoich.size()){
    	cout<<dvoich[j];
    	j++;
    }
	return 0;
}
