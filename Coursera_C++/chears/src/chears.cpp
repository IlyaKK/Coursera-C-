#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
    	int x,y = 0;
    	cin>>x>>y;
    	matrix[x-1][y-1] = 1;
    	if(x-1+1 >= 0 && x-1+1 <= n-1 && y-1-2 >= 0 && y-1-2 <= n-1){
    		matrix[x-1+1][y-1-2] = 1;
    	}
    	if(x-1+2 >= 0 && x-1+2 <= n-1 && y-1-1 >= 0 && y-1-1 <= n-1){
    		matrix[x-1+2][y-1-1] = 1;
    	}
    	if(x-1-2 >= 0 && x-1-2 <= n-1 && y-1-1 >= 0 && y-1-1 <= n-1){
    		matrix[x-1-2][y-1-1]= 1;
    	}
    	if(x-1-1 >= 0 && x-1-1 <= n-1 && y-1-2 >= 0 && y-1-2 <= n-1){
    		matrix[x-1-1][y-1-2] = 1;
    	}
    	if(x-1-2 >= 0 && x-1-2 <= n-1 && y-1+1 >= 0 && y-1+1 <= n-1){
    		matrix[x-1-2][y-1+1] = 1;
    	}
    	if(x-1-1 >= 0 && x-1-1 <= n-1 && y-1+2 >= 0 && y-1+2 <= n-1){
    		matrix[x-1-1][y-1+2]= 1;
    	}
    	if(x-1+1 >= 0 && x-1+1 <= n-1 && y-1+2 >= 0 && y-1+2 <= n-1){
    		matrix[x-1+1][y-1+2] = 1;
    	}
    	if(x-1+2 >= 0 && x-1+2 <= n-1 && y-1+1 >= 0 && y-1+1 <= n-1){
    		matrix[x-1+2][y-1+1] = 1;
    	}
    }
    int count = 0;
    for(int i = 0; i<n;i++){
    	for(int j = 0;j<n;j++){
    		if(matrix[i][j] == 1){
    			count++;
    		}
    	}
    }
    cout<<n*n-count<<' ';
	return 0;
}
