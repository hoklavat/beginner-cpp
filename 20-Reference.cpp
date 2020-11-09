//20-Reference
//reference directive: process with variable itself rather than creating a copy.

#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n1{100};
	int &r1{n1}; //r1 is reference to n1.
	vector<string> v1 {"Ali", "Burhan", "Cemal"};
	
	cout << "r1=" << r1 << ", n1=" << n1 << endl;
	r1 = 200;
	cout << "r1=" << r1 << ", n1=" << n1 << endl;
	
	for(auto s: v1)
		cout << s << " ";
	cout << endl;
	
	for(auto &s: v1) //const auto &s: error, const auto s: remains unchanged
		s = "None";
	
	for(auto s: v1)
		cout << s << " ";
	cout << endl;

	return 0;
}