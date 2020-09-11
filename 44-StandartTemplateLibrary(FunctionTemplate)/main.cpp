//44- Standart Template Library (Function Template)

#include <iostream>
#include <string>
using namespace std;

template <typename T>
T Min(T a, T b){
	return (a < b) ? a : b;
}

template <typename T1, typename T2>
void Print(T1 a, T2 b){
	cout << a << ", " << b << endl;
}

struct Person{
	string Name;
	int Age;
	bool operator<(Person &rhs)const{return this->Age < rhs.Age;}
};

ostream &operator<<(ostream &os, Person &p){
	os << p.Name;
	return os;
}

template <typename T>
void Swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}

int main(){
	Person p1{"Baris", 100};
	Person p2{"Bruce", 200};
	Person p3 = Min(p1, p2);
	
	cout << Min<int>(2, 3) << endl;
	cout << Min(2, 3) << endl;
	cout << Min('A', 'B') << endl;
	cout << Min(3.13, 3.256) << endl;
	cout << p3.Name << endl;
	cout << endl;
	
	Print<int, int>(10, 20);
	Print(10, 20);
	Print('A', "Boris");
	Print(20.4, true);
	Print(p1, p2);
	cout << endl;
	
	int a{100}, b{200};
	cout << a << ", " << b << endl;
	Swap(a, b);
	cout << a << ", " << b << endl;
	cout << endl;
	
	return 0;
}
