#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
	string c,z;
	int k=0;
	string buffer="";
	vector<string> numbers;
	vector<int> l;
    cin>>c;
    z = c + '.';
    for(const auto& p:z){
    	if(p != '.'){
    		buffer+=p;
    	}else{
            numbers.push_back(buffer);
            buffer.clear();
    	}
    }

        try{
        	for(const string& d:numbers){
        	    	if(stoi(d)>=0 && stoi(d)<=255){
        	            l.push_back(1);
        	    	}else if(stoi(d)<0 || stoi(d)>255){
        	    		l.push_back(0);
        	    	}
        	    }
        }
        catch(...){
        	l.push_back(0);
        }


    if(l.size()==4){
    for(const auto& q:l){
    	if(q==1){
    		k++;
    	}
    }
    }
    k < 4 ? cout<<0 : cout<<1;
	return 0;
}
