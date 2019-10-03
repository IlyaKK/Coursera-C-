#include <string>
#include <iomanip>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
using namespace std;

class Date {
public:
  Date(){
	  year = 0;
	  month = 0;
	  day = 0;
  }
  Date(int& y, int& m, int& d){
	  if(m<1 || m>12){
		  throw invalid_argument("Month value is invalid: "+ to_string(m));
	  }else if(d<1 || d>31){
		  throw invalid_argument("Day value is invalid: "+ to_string(d));
	  }
	  year=y;
	  month=m;
	  day=d;
  }
  int GetYear() const{
	return year;
  };
  int GetMonth() const{
	return month;
  };
  int GetDay() const{
	return day;
  };
private:
  int year;
  int month;
  int day;
};

bool operator<(const Date& lhs, const Date& rhs){
    if (lhs.GetDay() != rhs.GetDay()) {
        return lhs.GetDay() < rhs.GetDay();
    }
    else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    }
    else{
        return lhs.GetYear() < rhs.GetYear();
    }
}

/*ostream& operator<<(ostream& stream, const Date& date) {
    stream << setfill('0') << setw(4) << to_string(date.GetYear());
    stream << "-";
    stream << setfill('0') << setw(2) << to_string(date.GetMonth());
    stream << "-";
    stream << setfill('0') << setw(2) << to_string(date.GetDay());
    return stream;
}*/

class Database {
public:
  void AddEvent(const Date& date, const string& event){
	  basa[date].insert(event);
  };
  bool DeleteEvent(const Date& date, const string& event){
	  if(basa.count(date) && basa[date].count(event)>0){
		  basa[date].erase(event);
		  return true;
	  }else{
		  return false;
	  }
  };
  int  DeleteDate(const Date& date){
	  int N=0;
	  if (basa.count(date) > 0) {
	    N = basa.at(date).size();
	    basa.erase(date);
	  }
	  return N;
  };

void Find(const Date& date) const{
	if(basa.count(date)){
		for(auto k:basa.find(date)->second){
	       cout<<k<<endl;
		}
	}
};

  void Print() const{
	for(auto a:basa){
		cout << setw(4)<< setfill('0') << a.first.GetYear() << "-"<< setw(2) << setfill('0')<< a.first.GetMonth()<< "-"<< setw(2) << setfill('0')<< a.first.GetDay();
		for (auto b : a.second)
		cout<< " " << b;
		cout << endl;
		}
	};
private:
  map<Date,set<string>> basa;
};

Date InputDate(const string& date) {
	istringstream data(date);

	int year;
	data>>year;
	data.ignore(1);

	int month;
	data >> month;
	data.ignore(1);

	int day;
    data >> day;

	if (month > 12 || month < 1) {
		stringstream ss;
		ss << "Month value is invalid: " << month;
		throw domain_error(ss.str());
	}
	if (day > 31 || day < 1) {
		stringstream ss;
		ss << "Day value is invalid: " << day;
		throw domain_error(ss.str());
	}
	return Date(year, month, day);
}


int main() {

	Database db;
	string command;
	while (getline(cin, command)) {
		try {
			if (command == "Add") {
			stringstream ss (command);
			string date, event;
			ss >> date >> event;
			db.AddEvent(InputDate(date),event);
			}
			else if (com == "Del") {
			obj = InputDate(date);
			if (event != "") {
			if (db.DeleteEvent(obj, event)) {
			cout << "Deleted successfully" << endl;
			}
			else
			cout << "Event not found" << endl;
			}
			else {
			int i = db.DeleteDate(obj);
			cout << "Deleted " << i << " events" << endl;
			}
		}else if (com == "Find") {
		obj = InputDate(date);
		db.Find(obj);
		}
			else if (com == "Print") {
				db.Print();
			}
			else if (com == "" || com == " ") {}
			else
				cout << "Unknown command: " << com << endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
system("pause");
return 0;
}
