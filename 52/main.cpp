//52- Standart Template Library (Containers - Set)

#include <iostream>
#include <set>
using namespace std;

class Person{
	string Name;
	int Age;	
	friend ostream &operator<<(ostream &os, const Person &p);
public:
	Person(): Name{"Unknown"}, Age{0}{}
	Person(string n, int a): Name{n}, Age{a}{}
	bool operator<(const Person &p) const{
		return this->Age < p.Age;
	}
	bool operator==(const Person &p) const {
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
	set<int> s2{5, 2, 5, 3, 1, 2, 4, 3, 1, 4};
	set<Person> s3{{"Baris", 10}, {"Bruce", 20}};
	set<string> s4{"A", "B", "C"};
	
	Display(s1);
	Display(s2);	
	s1.insert(6);
	s2.insert(0);	
	Display(s1);
	Display(s2);
	
	cout << "5 in s1: " << s1.count(5) << endl;
	cout << "10 in s1: " << s1.count(10) << endl;
	auto it1 = s1.find(5);
	if(it1 != s1.end()) cout << "Found " << *it1 << endl;
	s1.clear();
	Display(s1);
	
	Display(s3);
	s3.emplace("Boris", 30);
	s3.emplace("Noris", 30); //no emplace, 30, <, key = age
	Display(s3);
	auto it2 = s3.find(Person("XXXX", 30)); //Boris
	if(it2 != s3.end()) s3.erase(it2);
	Display(s3);
	
	Display(s4);
	auto it3 = s4.insert("D"); //std::pair<iterator, bool>
	Display(s4);
	cout << boolalpha;
	cout << "First: " << *(it3.first) << endl;
	cout << "Second: " << it3.second << endl;
	it3 = s4.insert("A");
	Display(s4);
	cout << "First: " << *(it3.first) << endl;
	cout << "Second: " << it3.second << endl;

	return 0;
}
