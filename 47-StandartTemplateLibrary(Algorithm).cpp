//47-StandartTemplateLibrary(Algorithm)

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>
using namespace std;

class Person{
	string Name;
	int Age;
	
public:
	Person() = default; //compiler generates default constructor.
	Person(string n, int a): Name{n}, Age{a}{}
	
	bool operator<(const Person &p) const{
		return this->Age < p.Age;
	}
	
	bool operator==(const Person &p) const{
		return(this->Name == p.Name && this->Age == p.Age);
	}
};

int main(){
	vector<int> v{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	list<Person> l{{"Ali", 10}, {"Burhan", 20}, {"Cemil", 30}};
	string s{"Sabahattin"};
	
	//find the first index of 3.
	auto i1 = find(begin(v), end(v), 3); //begin(v) = v1.begin(), end(v) = v1.end()
	if(i1 != end(v))
		cout << "Number found at index: " << *i1 << endl;
	else
		cout << "Number not found." << endl;
	
	//count of 1s.
	int c1 = count(begin(v), end(v), 1);
	cout << "Count of 1s in vector: " << c1 << endl;
	
	//count of even numbers. numbers divisible by 2.
	int c2 = count_if(begin(v), end(v), [](int x){return(x % 2 == 0);}); //lambda expression
	cout << "Count of even numbers in vector: " << c2 << endl;
	
	//replace all 1s with 100.
	cout << "Before Replace -> v: ";
	for(auto e: v)
		cout << e << " ";
	cout << endl;
	replace(v.begin(), v.end(), 1, 100);
	cout << "After Replace -> v: ";
	for(auto e: v)
		cout << e << " ";
	cout << endl;	
	
	//perform specific operation on all elements.
	if(all_of(v.begin(), v.end(), [](int x){return(x < 200);}))
		cout << "All elements are less than 200." << endl;
	else
		cout << "All elements are not less than 200." << endl; 
	
	//find the first index of specified object.
	auto i2 = find(l.begin(), l.end(), Person{"Cemil", 30});
	if(i2 != l.end())
		cout << "Person found." << endl;
	else
		cout << "Person not found." << endl;
	
	//convert all characters in a string to uppercase.
	cout << "Before Uppercase -> String: " << s << endl;
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	cout << "After Uppercase -> String: " << s << endl;	

	return 0;
}