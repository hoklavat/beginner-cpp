//47- Standart Template Library (Algorithms)

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>
using namespace std;

class Person{
	string Name;
	int Age;
public:
	Person() = default;
	Person(string n, int a): Name{n}, Age{a}{}
	bool operator<(const Person &p) const{
		return this->Age < p.Age;
	}
	bool operator==(const Person &p) const{
		return(this->Name == p.Name && this->Age == p.Age);
	}
};

int main(){
	vector<int> v1{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	list<Person> l1{{"Baris", 10}, {"Bruce", 20}, {"Boris", 30}};
	string s1{"baris"};
	auto loc1 = find(begin(v1), end(v1), 3); //v1.begin(), v1.end()
	int c1 = count(begin(v1), end(v1), 1);
	int c2 = count_if(begin(v1), end(v1), [](int x){return(x % 2 == 0);}); //lambda expression
	auto loc2 = find(l1.begin(), l1.end(), Person{"Bruce", 20});
	
	if(loc1 != end(v1))
		cout << "Number found. " << *loc1 << endl;
	else
		cout << "Number not found." << endl;
	
	cout << "1 is found " << c1 << " times." << endl;
	cout << c2 << " even numbers found." << endl;	
	
	replace(v1.begin(), v1.end(), 1, 100);
	for(auto e: v1)
		cout << e << " ";
	cout << endl;
	
	if(all_of(v1.begin(), v1.end(), [](int x){return(x < 200);}))
		cout << "All elements are less than 200." << endl;
	else
		cout << "All elements are not less than 200." << endl; 
	
	if(loc2 != l1.end())
		cout << "Person found." << endl;
	else
		cout << "Person not found." << endl;
	
	transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
	cout << s1 << endl;	

	return 0;
}
