#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
  int q;
  cin >> q;
  map<set<string>, int> buses;
  string stop;
  for (int i = 0; i < q; ++i) {
    int n;
    cin >> n;
    set<string> stops;
    for(int i=0;i<n;i++){
    	cin >> stop;
    	stops.insert(stop);
    }
    if (buses.count(stops) == 0) {
      const int new_number = buses.size() + 1;
      buses[stops] = new_number;
      cout << "New bus " << new_number << endl;
    } else {
      cout << "Already exists for " << buses[stops] << endl;
    }
  }
  return 0;
}
