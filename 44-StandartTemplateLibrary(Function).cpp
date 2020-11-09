//44-StandartTemplateLibrary(Function)
//template allows a function or class to work on many different data types without being rewritten for each one.

#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

struct Person{
	string Name;
	int Age;
	
	bool operator<(Person &rhs) const{
		return this->Age < rhs.Age;
	}
};

ostream &operator<<(ostream &os, Person &p){
	os << p.Name;
	return os;
}

template <typename T>
T Min(T a, T b){
	return (a < b) ? a : b;
}

template <typename T1, typename T2>
void Print(T1 a, T2 b){
	cout << typeid(T1).name() << " - Variable 1: " << a << ", " << typeid(T2).name() << " - Variable 2: " << b << endl;
}

template <typename T>
void Swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}

int main(){
	Person p1{"Ali", 30};
	Person p2{"Burhan", 40};
	Person p3 = Min(p1, p2);
	
	//Minimum of Different Type
	cout << "Minimum of two integers (20, 30): " << Min<int>(20, 30) << endl;
	cout << "Minimum of two integers (20, 30): " << Min(20, 30) << endl;	
	cout << "Minimum of two characters (A, F): " << Min('A', 'F') << endl;
	cout << "Minimum of two decimals (3.13, 5.74): " << Min(3.13, 5.74) << endl;
	cout << "Minimum of two person instances by age (Ali/30, Burhan/40): " << p3.Name << endl;
	cout << endl;
	
	//Print Different Types
	Print<int, int>(10, 20);
	Print(10, 20);
	Print('A', "Cemal");
	Print(20.4, true);
	Print(p1, p2);
	cout << endl;
	
	//Swap Numbers
	int a{100}, b{200};
	cout << "Before Swap: a = " << a << ", b = " << b << endl;
	Swap(a, b);
	cout << "After Swap: a = " << a << ", b = " << b << endl;
	cout << endl;
	
	return 0;
}