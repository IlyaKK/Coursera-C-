#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
	int q;
	  cin >> q;
	  map<vector<string>,int> new_bus;
      for(int i=0; i < q; i++){
    	  int k;
    	  cin >> k;
    	  vector<string> stops(k);
    	  for(auto& t:stops){
    		  cin >> t;
    	  }
    	  if(new_bus.count(stops)){
    		 cout << " Already exists for " << new_bus[stops] << endl;
    	  }else{
    	  new_bus[stops];
    	  int t = new_bus.size();
    	  new_bus[stops] = t;
    	  cout << " New bus " << new_bus[stops] << endl;
    	  }
      }
      return 0;
}
