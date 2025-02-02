#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ���� ��� ����������, ���������� ������ ������
string FindNameByYear(const map<int, string>& names, int year) {
  string name;  // ���������� ��� ����������

  // ���������� ��� ������� �� ����������� ����� �������, �� ���� � ��������������� �������
  for (const auto& item : names) {
    // ���� ��������� ��� �� ������ �������, ��������� ���
    if (item.first <= year) {
      name = item.second;
    } else {
      // ����� ���� ������������, ��� ��� ��� ������ � ��� ����������� ��������� � ��������
      break;
    }
  }

  return name;
}

string FindNameByYear1(const map<int, string>& names, int year) {
  string n;  // ���������� ��� ����������
  vector<string> n1;
  // ���������� ��� ������� �� ����������� ����� �������, �� ���� � ��������������� �������
  for (const auto& item : names) {
    // ���� ��������� ��� �� ������ �������, ��������� ���
    if (item.first <= year) {
      n1.push_back(item.second);
    } else {
      // ����� ���� ������������, ��� ��� ��� ������ � ��� ����������� ��������� � ��������
      break;
    }
  }

  auto last = unique(n1.begin(), n1.end());
      n1.erase(last, n1.end());

  if(n1.size()==1){
	  return n1[0];
  }else if(n1.size()>1){
	  n=n1[n1.size()-1]+" (";
	  for(int i=n1.size()-2; i>=0; i--){
		  n+=n1[i]+", ";
	  }
	  int x1 = n.size() - 2;
	  n = n.erase(x1);
	  n+=")";
  }
  return n;
}

class Person {
public:
    Person(const string& f_n, const string& l_n, int year) {
    	first_names[year] = f_n;
        birth_year = year;
        for (auto& i : first_names) {
            if (i.first < year) first_names.erase(i.first);
        }
        last_names[year] = l_n;
        birth_year = year;
        for (auto& k : first_names) {
            if (k.first < year) last_names.erase(k.first);
        }
    }

  void ChangeFirstName(int year, const string& first_name) {
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    last_names[year] = last_name;
  }
  string GetFullName(int year) const{
    // �������� ��� � ������� �� ��������� �� ��� year
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);

    // ���� � ���, � ������� ����������
    if(birth_year != 0 && year < birth_year){
    	return "No person";
    } else if (first_name.empty() && last_name.empty()) {
      return "Incognito";

    // ���� ���������� ������ ���
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";

    // ���� ���������� ������ �������
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";

    // ���� �������� � ���, � �������
    } else {
      return first_name + " " + last_name;
    }
  }
  string GetFullNameWithHistory(int year) const{
    // �������� ��� ����� � ������� �� ��������� �� ����� ���� year
	  // �������� ��� � ������� �� ��������� �� ��� year
	      const string first_name1 = FindNameByYear1(first_names, year);
	      const string last_name1 = FindNameByYear1(last_names, year);

	      // ���� � ���, � ������� ����������
	      if(birth_year != 0 && year < birth_year){
	          	return "No person";
	      } else if(first_name1.empty() && last_name1.empty()) {
	        return "Incognito";
	      // ���� ���������� ������ ���
	      } else if (first_name1.empty()) {
	        return last_name1 + " with unknown first name";

	      // ���� ���������� ������ �������
	      } else if (last_name1.empty()) {
	        return first_name1 + " with unknown last name";

	      // ���� �������� � ���, � �������
	      } else {
	        return first_name1 + " " + last_name1;
	      }
  }

private:
  map<int, string> first_names;
  map<int, string> last_names;
  int birth_year = 0;
};

int main() {
	  Person person("Polina", "Sergeeva", 1960);
	  for (int year : {1959, 1960}) {
	    cout << person.GetFullNameWithHistory(year) << endl;
	  }

	  person.ChangeFirstName(1965, "Appolinaria");
	  person.ChangeLastName(1967, "Ivanova");
	  for (int year : {1965, 1967}) {
	    cout << person.GetFullNameWithHistory(year) << endl;
	  }
  return 0;
}
