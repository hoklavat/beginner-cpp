//48- Standart Template Library (Containers - Array)

#include <iostream>
#include <array>
#include <algorithm>
#include <numeric> //accumulate
using namespace std;

Display(const array<int, 5> &a){
	for(const int &e: a)
		cout << e << " ";
	cout << endl;
}

int main(){
	array<int, 5> a1{1, 2, 3, 4, 5};
	array<int, 5> a2;
	a2 = {10, 20, 30, 40, 50};
	int *p1 = a1.data();
	array<int, 5>::iterator it1 = min_element(a1.begin(), a1.end());
	array<int, 5>::iterator it2 = max_element(a1.begin(), a1.end());
	auto it3 = adjacent_find(a1.begin(), a1.end());
	int i1 = accumulate(a1.begin(), a1.end(), 0);
	int i2 = count(a1.begin(), a1.end(), 3);
	int i3 = count_if(a1.begin(), a1.end(), [](int x){return x < 4;});
	
	Display(a1);
	cout << "a1 size: " << a1.size() << endl;
	cout << "a1 front: " << a1.front() << endl;
	cout << "a1 back: " << a1.back() << endl;
	cout << "a1 minimum: " << *it1 << endl;
	cout << "a1 maximum: " << *it2 << endl;
	if(it3 != a1.end()) cout << "Adjacent element found in a1. " << *it3 << endl;
	cout << "a1 sum of elements: " << i1 << endl;
	cout << "a1 count of 3: " << i2 << endl;
	cout << "a1 count of numbers smaller than 4: " << i3 << endl;
	
	a1[4] = 6; //no bounds check
	a2.at(4) = 60; //bounds check
	Display(a1);
	Display(a2);
	
	a1.swap(a2);
	a2.fill(0);
	Display(a1);
	Display(a2);
	
	cout << "p1: " << p1 << endl;
	*p1 = 1;
	Display(a1);
	
	a1 = {5, 7, 8, 9, 6};
	Display(a1);
	sort(a1.begin(), a1.end());
	Display(a1);
	cout << endl;

	return 0;
}
