#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, d,cn, max, max_val,i= 0;
    cin>>n;
    vector<int> a;
    for(int i=0; i<n; i++){
       cin>>d;
       a.push_back(d);
   }
  sort(begin(a),end(a));
  while(i<int(a.size())){
      cn = count(begin(a)+i,end(a),a[i]);
      if(cn == int(a.size())){
    	  max_val = a[i];
    	  break;
      }else if(max <= cn){
    	  max = cn;
    	  max_val = a[i];
      }
      i = i+cn;
   }
   cout<<max_val;;
   return 0;
}
