//51- Standart Template Library (Containers - List)

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator> //std::advance
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
void Display(const list<T> &l){
	cout << "[ ";
	for(const auto &e: l)
		cout << e << " ";
	cout << "]" << endl;
}

int main(){
	list<int> l1{1, 2, 3, 4, 5};
	list<int> l2(5, 1);
	list<string> l3;
	list<Person> l4{{"Baris", 10}, {"Bruce", 20}};
	
	Display(l1);
	Display(l2);
	cout << "l1 size: " << l1.size() << endl;
	cout << "l1 front: " << l1.front() << endl;
	cout << "l1 back: " << l1.back() << endl;
	l1.clear();
	Display(l1);
	l1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Display(l1);
	l1.resize(15);
	Display(l1);
	auto it1 = find(l1.begin(), l1.end(), 5);
	if(it1 != l1.end()) l1.insert(it1, 0);
	Display(l1);
	l1.insert(it1, l2.begin(), l2.end());
	Display(l1);
	advance(it1, 1);
	cout << "*it1: " << *it1 << endl;
	l1.erase(it1);
	Display(l1);
	
	l3.push_back("Baris");
	l3.push_front("Bruce");
	Display(l3);
	
	l4.resize(5);
	Display(l4);
	l4.emplace_back("Boris", 30);
	Display(l4);
	auto it2 = find(l4.begin(), l4.end(), Person{"Boris", 30});
	if(it2 != l4.end()) l4.emplace(it2, "Noris", 40);
	Display(l4);
	l4.sort();
	Display(l4);

	return 0;
}
