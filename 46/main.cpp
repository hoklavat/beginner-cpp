//46- Standart Template Library (Iterators)

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
	vector<int> v1{1, 2, 3, 4, 5};
	list<string> l1{"Baris", "Bruce", "Boris"}; //next-previous
	map<int, string> m1{{1, "Baris"}, {2, "Bruce"}, {3, "Boris"}}; //key-value
	
	auto i1 = v1.begin(); //vector<int>::iterator i1;
	vector<int>::const_iterator i2 = v1.begin(); //cannot change the value of what it points, read-only
	vector<int>::reverse_iterator i3 = v1.rbegin();
	list<string>::const_reverse_iterator i4 = l1.crbegin();
	map<int, string>::iterator i5 = m1.begin();
	
	Display(v1);
	cout << *i1 << endl;
	i1++;
	cout << *i1 << endl;
	i1 = v1.end() - 1;
	cout << *i1 << endl;
	i2 += 2;
	cout << *i2 << endl;
	
	i1 = v1.begin();
	while(i1 != v1.end()){
		*i1 *= 2;
		i1++;
	}
	Display(v1);
	
	while(i3 != v1.rend()){
		cout << *i3 << " ";
		i3++;
	}
	cout << endl;
	
	i4++;
	cout << *i4 << endl;
	
	while(i5 != m1.end()){
		cout << i5->first << " : " << i5->second << endl;
		i5++;
	}	
	cout << endl;

	return 0;
}
