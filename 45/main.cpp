//45- Standart Template Library (Class Template)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class Item{
private:
	string Name;
	T Value;
public:
	Item(string n, T v):Name{n}, Value{v}{}
	string GetName() const{return Name;}
	T GetValue() const{return Value;}
};

template <typename T1, typename T2>
struct MyPair{
	T1 First;
	T2 Second;
};

template <typename T, int N>
class Array{
	int Size{N};
	T Values[N];
	
	friend ostream &operator<<(ostream &os, Array<T, N> &a){
		os << "[ ";
		for(const auto &v: a.Values)
			os << v << " ";
		os << "]" << endl;
		return os;
	}
public:
	Array() = default;
	
	Array(T v){
		for(auto &i: Values)
			i = v;
	}
	
	void Fill(T v){
		for(auto &i: Values)
			i = v;
	}
	
	int GetSize(){
		return Size;
	}
	
	T &operator[](int i){
		return Values[i];
	}	
};

int main(){
	
	Item<int> i1{"Baris", 100};
	Item<string> i2{"Baris", "Yildiz"};
	Item<Item<string>> i3{"Baris", {"Bruce", "Boris"}};
	vector<Item<double>> v1{};
	MyPair<int, double> p1{123, 321.45};
	Array<int, 5> a1{1};
	Array<string, 5> a2{string{"PO"}};
	
	cout << i1.GetName() << ", " << i1.GetValue() << endl;
	cout << i2.GetName() << ", " << i2.GetValue() << endl;
	cout << i3.GetName() << ", " << i3.GetValue().GetName() << ", " << i3.GetValue().GetValue() << endl;
	
	v1.push_back(Item<double>{"Baris", 100.12});
	v1.push_back(Item<double>{"Bruce", 200.23});
	v1.push_back(Item<double>{"Boris", 300.34});
	for(const auto &i: v1)
		cout << i.GetName() << ", " << i.GetValue() << endl;
	
	cout << p1.First << ", " << p1.Second << endl;	
	cout << a1.GetSize() << ", " << a1;
	a1.Fill(10);
	a1[2] = 100;
	cout << a1.GetSize() << ", " << a1;
	
	a2[2] = string{"KO"};
	cout << a2.GetSize() << ", " << a2;
	a2.Fill(string{"BO"});
	cout << a2.GetSize() << ", " << a2;
	cout << endl;

	return 0;
}
