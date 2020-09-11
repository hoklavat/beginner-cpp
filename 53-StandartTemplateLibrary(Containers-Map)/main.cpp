//53- Standart Template Library (Containers - Map)

#include <iostream>
#include <map>
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
	map<string, int> m1{{"Baris", 10}, {"Bruce", 20}, {"Boris", 30}};
	map<string, set<int>> m2{{"A", {1, 2, 3, 4, 5}}, {"B", {6, 7, 8, 9}}};
	
	Display(m1);
	m1.insert(pair<string, int>("Noris", 40));
	Display(m1);
	m1.insert(make_pair("Loris", 50));
	Display(m1);
	m1["Baris"] = 5;
	Display(m1);
	m1["Baris"] += 5;
	Display(m1);
	cout << "Noris Exists: " << m1.count("Noris") << endl;
	m1.erase("Noris");
	Display(m1);
	cout << "Noris Exists: " << m1.count("Noris") << endl;
	auto it1 = m1.find("Baris");
	if(it1 != m1.end()) cout << it1->first << ":" << it1->second << endl;
	m1.clear();
	Display(m1);
	
	Display(m2);
	m2["B"].insert(10);
	Display(m2);
	auto it2 = m2.find("A");
	if(it2 != m2.end()) it2->second.insert(0);
	Display(m2);

	return 0;
}
