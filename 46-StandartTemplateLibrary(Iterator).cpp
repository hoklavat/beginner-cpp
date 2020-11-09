//46-StandartTemplateLibrary(Iterator)

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
using namespace std;

void Display(vector<int> &vec){
	cout << "[ ";
	for(auto const &e: vec)
		cout << e << " ";
	cout << "]" << endl;
}

int main(){
	vector<int> v{1, 2, 3, 4, 5};
	list<string> l{"Ali", "Burhan", "Cemil"}; //next-previous
	map<int, string> m{{1, "Ali"}, {2, "Burhan"}, {3, "Cemil"}}; //key-value
	
	cout << "Contents of Vector: ";
	Display(v);
	
	//iterator
	auto it1 = v.begin(); //vector<int>::iterator it1 = v.begin();	
	cout << "First Element of Vector -> *it1: " << *it1 << endl;	
	it1++;
	cout << "Second Element of Vector -> *it1: " << *it1 << endl;	
	it1 = v.end() - 1;
	cout << "Last Element of Vector -> *it1: " << *it1 << endl;	
	it1 += 2;
	cout << "Off Limits: " << *it1 << endl;
	cout << "------------------------------------------" << endl;
	
	//constant iterator: read-only. value cannot be changed.
	vector<int>::const_iterator it2 = v.begin();
	it2 = v.begin();
	while(it2 != v.end()){
		//*it2 *= 2; //read-only. value cannot be changed.
		it2++;
	}
	Display(v);
	cout << "------------------------------------------" << endl;
	
	//reverse iterator
	vector<int>::reverse_iterator it3 = v.rbegin();
	while(it3 != v.rend()){
		cout << "Reverse Iteration -> *it3: " << *it3 << endl;
		it3++;
	}
	cout << "------------------------------------------" << endl;
	
	//constant-reverse iterator
	list<string>::const_reverse_iterator it4 = l.crbegin();
	cout << "Constant Reverse Iteration -> *it4: " << *it4 << endl;
	it4++;
	cout << "Constant Reverse Iteration -> *it4: " << *it4 << endl;
	cout << "------------------------------------------" << endl;
	
	map<int, string>::iterator it5 = m.begin();	
	while(it5 != m.end()){
		cout << "Map Iteration -> First: "<< it5->first << " - Second: " << it5->second << endl;
		it5++;
	}	
	cout << endl;

	return 0;
}