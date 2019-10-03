#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
	  sorted_strings.push_back(s);// добавить строку s в набор
  }
  vector<string> GetSortedStrings() {
	sort(sorted_strings.begin(),sorted_strings.end());
    return sorted_strings;// получить набор из всех добавленных строк в отсортированном порядке
  }
private:
  vector<string> sorted_strings;// приватные поля
};
