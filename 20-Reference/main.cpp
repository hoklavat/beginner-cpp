//20- Reference

#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n1{100};
	int &r1{n1};	
	vector<string> v1 {"CAT", "DOG", "PIG"};
	
	cout << "n1: " << n1 << endl;
	r1 = 200;
	cout << "n1: " << n1 << endl;
	
	for(auto s: v1)
		cout << s << " ";
	cout << endl;
	
	for(auto &s: v1) //const auto &s: error, const auto s: remains unchanged
		s = "NONE";
	
	for(auto s: v1)
		cout << s << " ";
	cout << endl;

	return 0;
}
