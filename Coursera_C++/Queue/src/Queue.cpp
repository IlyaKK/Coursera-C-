#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void peopleQueue() {
	vector<bool> queue;
	int n;
	int number;
	string command;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == "COME") {
			cin >> number;
			queue.resize(queue.size() + number);
		} else if (command == "WORRY" || command == "QUIET") {
			cin >> number;
			queue[number]=(command=="WORRY");
		} else if (command == "WORRY_COUNT") {
			cout << count(begin(queue), end(queue), true) <<endl;
		} else {
			cout << "Unknown operation" << endl;
		}
}
}


int main() {
		peopleQueue();
		return 0;
}
