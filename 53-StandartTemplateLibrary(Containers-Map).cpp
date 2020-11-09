//53-StandartTemplateLibrary(Containers-Map)

#include <iostream>
#include <map>
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

void Display(const map<string, set<int>> &m){
	cout << "[ ";
	for(const auto &e: m){
		cout << e.first << ":[ ";
		for(const auto &se: e.second)
			cout << se << " ";
		cout << "] ";
	}
	cout << "]" << endl;
}

template<typename T1, typename T2>
void Display(const map<T1, T2> &m){
	cout << "[ ";
	for(const auto &e: m)
		cout << e.first << ":" << e.second << " ";		
	cout << "]" << endl;
}

int main(){
	map<string, int> m1{{"Ali", 10}, {"Burhan", 20}, {"Cemil", 30}};
	cout << "m1: ";
	Display(m1);
	m1.insert(pair<string, int>("Durdu", 40));
	cout << "m1.insert(pair<string, int>(Durdu, 40)) -> m1: ";
	Display(m1);
	m1.insert(make_pair("Emrah", 50));
	cout << "m1.insert(make_pair(Emrah, 50)) -> m1: ";
	Display(m1);
	
	m1["Burhan"] = 5;
	cout << "m1[Burhan] = 5 -> m1: ";
	Display(m1);
	
	m1["Burhan"] += 5;
	cout << "m1[Burhan] += 5 -> m1: ";
	Display(m1);
	
	cout << "Does Emrah Exists? " << m1.count("Emrah") << endl;
	m1.erase("Emrah");
	cout << "m1.erase(Emrah) -> m1: ";
	Display(m1);
	cout << "Does Emrah Exists? " << m1.count("Emrah") << endl;
	auto it1 = m1.find("Durdu");
	if(it1 != m1.end()) 
		cout << it1->first << " is found. " << it1->first << ":" << it1->second << endl;
	m1.clear();
	cout << "m1.clear -> m1: ";
	Display(m1);
	
	map<string, set<int>> m2{{"A", {1, 2, 3, 4, 5}}, {"B", {6, 7, 8, 9}}};
	cout << endl << "m2: ";
	Display(m2);
	m2["B"].insert(10);
	cout << "m2[B].insert(10) -> m2: ";
	Display(m2);
	auto it2 = m2.find("A");
	if(it2 != m2.end()) 
		it2->second.insert(0);
	cout << "After Insertion 0 to A -> m2: ";
	Display(m2);

	return 0;
}