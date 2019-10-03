#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
	int n_strings;
	int m_columns;
	int value;
	ifstream input("input.txt");
	if(input){
		input>>n_strings;
		input.ignore(1);
		input>>m_columns;
		for(int i=1;i<=n_strings;i++){
		  for(int j=1;j<=m_columns;j++){
			  input>>value;
			  cout<<setw(10)<<value;
			  if(j<m_columns){
				cout<<' ';
			  }
			  input.ignore(1);
		  }
		 if(i<n_strings){
			 cout<<endl;
		 }
		}
	}else{
		cout<<'n';
	}
	return 0;
}
