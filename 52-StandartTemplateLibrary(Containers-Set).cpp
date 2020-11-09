//52-StandartTemplateLibrary(Containers-Set)

#include <iostream>
#include <set>
using namespace std;

class Person{
	string Name;
	int Age;	
	friend ostream &operator<<(ostream &os, const Person &p);
	
public:
	Person(): Name{"None"}, Age{0}{}
	Person(string n, int a): Name{n}, Age{a}{}
	
	bool operator<(const Person &p) const{
		return this->Age < p.Age;
	}
	
	bool operator==(const Person &p) const{
		return (this->Name == p.Name && this->Age == p.Age);
	}
};

ostream &operator<<(ostream &os, const Person &p){
	os << p.Name << ":" << p.Age;
	return os;
}

template <typename T>
void Display(const set<T> &s){
	cout << "[ ";
	for(const auto &e: s)
		cout << e << " ";
	cout << "]" << endl;
}

int main(){	
	set<int> s1{5, 3, 2, 4, 1};
	cout << "s1: ";
	Display(s1);
	s1.insert(6);
	cout << "After Insertion -> s1: ";
	Display(s1);
	cout << "Count of 5 in s1: " << s1.count(5) << endl;
	cout << "Count of 10 in s1: " << s1.count(10) << endl;
	auto it1 = s1.find(5);
	if(it1 != s1.end()) cout << *it1 << " is found in s1." << endl;
	s1.clear();
	cout << "After Clear -> s1: ";
	Display(s1);
	
	set<int> s2{5, 2, 5, 3, 1, 2, 4, 3, 1, 4};
	cout << endl << "s2: ";
	Display(s2);
	s2.insert(0);
	cout << "After Insertion -> s2: ";
	Display(s2);	
	
	set<Person> s3{{"Ali", 10}, {"Burhan", 20}};
	cout << endl << "s3: ";
	Display(s3);
	s3.emplace("Cemil", 30);
	s3.emplace("Durdu", 30); //no emplace, 30, <, key = age
	cout <<  "After Emplace -> s3: ";
	Display(s3);
	auto it2 = s3.find(Person("Cemil", 30));
	if(it2 != s3.end()) s3.erase(it2);
	cout <<  "After Erase -> s3: ";
	Display(s3);
	
	set<string> s4{"A", "B", "C"};
	cout << endl << "s4: ";
	Display(s4);
	auto it3 = s4.insert("D"); //std::pair<iterator, bool>
	cout << "After Insertion -> s4: ";
	Display(s4);
	cout << boolalpha;
	cout << "*(it3.first): " << *(it3.first) << endl;
	cout << "it3.second: " << it3.second << endl;
	it3 = s4.insert("A");
	cout << "it3 = s4.insert(A) -> s4: ";
	Display(s4);
	cout << "*(it3.first): " << *(it3.first) << endl;
	cout << "it3.second: " << it3.second << endl;

	return 0;
}