#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Next_month(int& k,const vector<int>& days_in_months, vector<vector<string>>& work_in_day) {
	vector<vector<string>> copy;
	k++;
	if(k>11)k=0;
	if( days_in_months[k] > days_in_months[k-1] ){
	 work_in_day.resize(days_in_months[k]);
	 }else if( days_in_months[k] < days_in_months[k-1] ){
	  copy = work_in_day;
	  work_in_day.resize(days_in_months[k]);
	  int l = work_in_day.size(); // размер нового вектора
	  int g = days_in_months[k-1]; // размер старого вектора
	  const int y = l-1; // переменная для определения индекса последнего элемента нового вектора
	  for (l; g > l; l++) {
	  work_in_day[y].insert(end(work_in_day[y]), begin(copy[l]), end(copy[l])); //все задачи из дня старого месяца дописываем в конец последнего дня нового месяца
	  }
	  copy.clear();
	  }
}

void Task_display(int j, const vector<vector<string>>& work_in_day){
	cout << work_in_day[j - 1].size();
	for (auto i : work_in_day[j - 1]){
	   cout << " " << i;
	}
	cout<<endl;
}

int main() {
	int n;
	int j;
	int k=0;
	string command;
	vector<int> days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<vector<string>> work_in_day;
	work_in_day.resize(days_in_months[k], {});
	string work;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> command;

		if(command == "NEXT"){
	       Next_month(k, days_in_months, work_in_day);

		}else if(command == "DUMP"){
			cin >> j;
			Task_display(j,work_in_day);
		}else if(command == "ADD"){
			cin >> j >> work;
			work_in_day[j-1].push_back(work);
	}
	}
	return 0;
}
