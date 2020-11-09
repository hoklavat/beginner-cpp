//45-StandartTemplateLibrary(Class)

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
	Item(string n, T v): Name{n}, Value{v}{}
	
	string GetName() const{
		return Name;
	}
	
	T GetValue() const{
		return Value;
	}
};

template <typename T1, typename T2>
struct MyPair{
	T1 First;
	T2 Second;
};

template <typename T, int N>
class Array{
private:	
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
	
	//integer type item
	Item<int> i1{"Ali", 20};
	
	//string type item
	Item<string> i2{"Burhan", "Bicer"};
	
	//item of string type item
	Item<Item<string>> i3{"Cemil", {"Riza", "Goksu"}};
	
	//vector of double type item
	vector<Item<double>> v1{};
	
	//pair of integer and double
	MyPair<int, double> p1{123, 321.45};
	
	//integer type of array with 5 elements initialized with 1.
	Array<int, 5> a1{1};
	
	//string type of array with 5 elements initialized with None.
	Array<string, 5> a2{string{"Foo"}};
	
	cout << "Integer type of item -> Name: " << i1.GetName() << ", Value: " << i1.GetValue() << endl;
	cout << "String type of item -> Name: " << i2.GetName() << ", Value: " << i2.GetValue() << endl;
	cout << "Item type of string type of item -> Name: " << i3.GetName() << ", Value.Name: " << i3.GetValue().GetName() << ", Value.Value: " << i3.GetValue().GetValue() << endl;
	cout << endl;
	
	v1.push_back(Item<double>{"Dogus", 10.12});
	v1.push_back(Item<double>{"Erdil", 20.23});
	v1.push_back(Item<double>{"Ferdi", 30.34});
	for(const auto &i: v1)
		cout << "Name: " << i.GetName() << ", Value: " << i.GetValue() << endl;
	cout << endl;
	
	cout << "Pair -> First Element: " << p1.First << ", Second Element: " << p1.Second << endl;
	cout << endl;
	
	cout << "Array -> Size: " << a1.GetSize() << ", Contents: " << a1;
	a1.Fill(10);
	a1[2] = 100;
	cout << "Array -> Size: " << a1.GetSize() << ", Contents: " << a1;
	cout << endl;
	
	a2[2] = string{"Bar"};
	cout << "Array -> Size: " << a2.GetSize() << ", Contents: " << a2;
	a2.Fill(string{"NaN"});
	cout << "Array -> Size: " << a2.GetSize() << ", Contents: " << a2;
	cout << endl;

	return 0;
}