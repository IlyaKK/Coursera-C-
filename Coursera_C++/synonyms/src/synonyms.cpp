#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


int main(){
	int q;
	string command, word1, word2;
	map<string,set<string>> synonyms;
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> command;
		if(command == "ADD"){
			cin >> word1 >> word2;
			synonyms[word1].insert(word2);
			synonyms[word2].insert(word1);
		}else if(command == "COUNT"){
			cin >> word1;
			cout << synonyms[word1].size() << endl;
		}else if(command == "CHECK"){
			cin >> word1 >> word2;
			if(synonyms[word1].count(word2)){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
