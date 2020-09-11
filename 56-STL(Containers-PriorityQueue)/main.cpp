//56- Standart Template Library (Containers - Priority Queue)

#include <iostream>
#include <queue>
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

template <typename T>
void Display(priority_queue<T> q){
	cout << "[ ";
	while(!q.empty()){
		T e = q.top();
		q.pop();
		cout << e << " ";
	}
	cout << "]" << endl;
}

int main(){
	priority_queue<int> p1;
	priority_queue<Person> p2;
	
	for(int i: {4, 9, 1, 0, 4, 3, 6, 7, 3, 3, 5, 8})
		p1.push(i);
	Display(p1);
	cout << "Size: " << p1.size() << endl;
	cout << "Top: " << p1.top() << endl;
	p1.pop();
	Display(p1);
	
	p2.push(Person("Baris", 10));
	p2.push(Person("Bruce", 20));
	p2.push(Person("Boris", 30));
	Display(p2);

	return 0;
}
