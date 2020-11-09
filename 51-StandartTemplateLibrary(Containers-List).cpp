//51-StandartTemplateLibrary(Containers-List)

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
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
	list<int> l1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "l1: ";
	Display(l1);
	cout << "l1 size: " << l1.size() << endl;
	cout << "l1 front: " << l1.front() << endl;
	cout << "l1 back: " << l1.back() << endl;
	l1.clear();
	cout << "l1.clear() -> l1: ";
	Display(l1);
	l1 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	cout << "l1 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100} -> l1: ";
	Display(l1);
	l1.resize(15);
	cout << "l1.resize(15) -> l1: ";
	Display(l1);
	auto it1 = find(l1.begin(), l1.end(), 50);
	if(it1 != l1.end()) l1.insert(it1, 15);
	cout << "After Insertion of 15 -> l1: ";
	Display(l1);
	
	list<int> l2(10, 1);
	cout << "l2: ";
	Display(l2);
	l1.insert(it1, l2.begin(), l2.end());
	cout << "After Insertion of l2 -> l1: ";
	Display(l1);
	advance(it1, 1);
	cout << "advance(it1, 1) -> *it1: " << *it1 << endl;
	l1.erase(it1);
	cout << "After Deletion by Iterator -> l1: ";
	Display(l1);
	
	list<string> l3;
	l3.push_back("Durdu");
	l3.push_front("Ezrail");
	cout << "l3: ";
	Display(l3);
	
	list<Person> l4{{"Ali", 10}, {"Burhan", 20}};
	cout << "l4: ";
	Display(l4);
	l4.resize(5);
	cout << "After Resize -> l4: ";
	Display(l4);
	l4.emplace_back("Cemil", 30);
	cout << "After Emplace Back -> l4: ";
	Display(l4);
	
	auto it2 = find(l4.begin(), l4.end(), Person{"Cemil", 30});
	if(it2 != l4.end()) l4.emplace(it2, "Cevahir", 40);
	cout << "After Find and Emplace -> l4: ";
	Display(l4);	
	l4.sort();
	cout << "After Sort -> l4: ";
	Display(l4);

	return 0;
}