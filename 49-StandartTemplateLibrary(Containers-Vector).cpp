//49-StandartTemplateLibrary(Containers-Vector)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person{
	string Name;
	int Age;	
	friend ostream &operator<<(ostream &os, const Person &p);
	
public:
	Person() = default;
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
void Display1(const vector<T> &v){
	cout << "[ ";
	for(const auto &e: v)
		cout << e << " ";
	cout << "]" << endl;
}

void Display2(const vector<int> &v){
	cout << "[ ";
	for_each(v.begin(), v.end(), [](int x){cout << x << " ";});
	cout << "]" << endl;
}

int main(){
	vector<int> v1{1, 2, 3, 4 ,5};
	cout << "v1: ";
	Display1(v1);
	
	v1 = {50, 30, 40, 10, 20};
	cout << "v1 = {50, 30, 40, 10, 20} -> v1:";
	Display2(v1);
	
	v1.at(0) = 20;
	cout << "v1.at(0) = 20 -> v1: ";
	Display2(v1);
	
	v1[3] = 50;
	cout << "v1[3] = 50 -> v1: ";
	Display2(v1);
	
	sort(v1.begin(), v1.end());
	cout << "sort(v1.begin(), v1.end()) -> v1: ";
	Display2(v1);
	
	vector<int> v2(10, 5);
	cout << endl << "v2: ";
	Display2(v2);
	
	vector<int> v4;
	//multiply elements with same indexes in v1 and v2, store it in v4. 
	transform(v1.begin(), v1.end(), v2.begin(), back_inserter(v4), [](int x, int y){return x * y;});
	cout << endl << "v4: ";
	Display2(v4);	
	auto it1 = find(v4.begin(), v4.end(), 150);
	if(it1 != v4.end()) v4.insert(it1, v1.begin(), v1.end()); //insert v1 into v4 before 150.
	cout << "v4 after insertion: ";
	Display2(v4);
	
	cout << endl << "v1: ";
	Display2(v1);
	cout << "v1 size: " << v1.size() << endl;
	cout << "v1 capacity: " << v1.capacity() << endl;
	cout << "v1 max_size: " << v1.max_size() << endl;	
	v1.push_back(60);
	cout << "v1.push_back(60) -> v1: ";
	Display2(v1);
	cout << "                 -> v1 new size: " << v1.size() << endl;
	cout << "                 -> v1 new capacity: " << v1.capacity() << endl;
	v1.shrink_to_fit();
	cout << "v1.shrink_to_fit() -> v1 new size: " << v1.size() << endl;
	cout << "                   -> v1 new capacity: " << v1.capacity() << endl;
	v1.reserve(100);
	cout << "v1.reserve(100) -> v1 new size: " << v1.size() << endl;
	cout << "                -> v1 new capacity: " << v1.capacity() << endl;
	
	cout << endl << "v2: ";
	Display1(v2);	
	v2.clear();
	cout << "v2.clear() -> v1: ";
	Display1(v2);
	v2 = {1, 2, 3, 4, 5, 6, 7 , 8, 9, 10, 11};
	cout << "v2 = {1, 2, 3, 4, 5, 6, 7 , 8, 9, 10, 11} -> v1: ";
	Display1(v2);
	v2.erase(v2.begin(), v2.begin() + 2);
	cout << "v2.erase(v2.begin(), v2.begin() + 2) -> v1: ";
	Display1(v2);
	
	cout << "v2: ";
	Display1(v2);
	
	auto it2 = v2.begin();
	while(it2 != v2.end()){
		if(*it2 % 2 == 0) v2.erase(it2);
		else it2++;			
	}
	cout << "Erase even numbers - > v2: ";
	Display1(v2);
	
	v2.swap(v1);
	cout << "After swap - > v2: ";
	Display1(v2);
	
	copy(v1.begin(), v1.end(), back_inserter(v2));
	cout << "After insertion - > v2: ";
	Display2(v2);	
	
	copy_if(v1.begin(), v1.end(), back_inserter(v2), [](int x){return x % 2 != 0;});
	cout << "Insert odd numbers of v1 into v2 - > v2: ";
	Display2(v2);
	
	vector<Person> v3;
	Person p1{"Cemil", 30};
	cout << endl << "v3: ";
	Display1(v3);
	v3.push_back(Person{"Ali", 10});
	v3.emplace_back("Burhan", 20);
	v3.push_back(p1);
	v3.push_back(p1);
	cout << "v3.push_back(p1) -> v3: ";
	Display1(v3);
	v3.pop_back();
	cout << "v3.pop_back() -> v3: ";
	Display1(v3);
	cout << "v3 front: " << v3.front() << endl;
	cout << "v3 back: " << v3.back() << endl;	

	return 0;
}