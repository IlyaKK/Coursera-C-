#include <iostream>
#include <string>

using namespace std;

struct Specialization{
	string value;
	explicit Specialization(string new_value){
		value = new_value;
	}
};

struct Course{
	string value;
	explicit Course(string new_value){
		value = new_value;
	}
};

struct Week{
	string value;
	explicit Week(string new_value){
		value = new_value;
	}
};

struct LectureTitle {
  string specialization;
  string course;
  string week;

  LectureTitle(Specialization n_specialization, Course n_course, Week n_week){
	  specialization = n_specialization.value;
	  course = n_course.value;
	  week = n_week.value;
  }
};

int main() {
	LectureTitle title(
	    Specialization("C++"),
	    Course("White belt"),
	    Week("4th")
	);
	return 0;
}
