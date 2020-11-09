//48-StandartTemplateLibrary(Containers-Array)

#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>
using namespace std;

Display(const array<int, 5> &a){
	cout << "[ ";
	for(const int &e: a)
		cout << e << " ";
	cout << "]" << endl;
}

int main(){
	array<int, 5> a1{1, 2, 3, 4, 5};
	
	array<int, 5> a2;
	a2 = {10, 20, 30, 40, 50};
	
	cout << "Contents of array a1: ";
	Display(a1);	
	
	cout << "a1 size: " << a1.size() << endl;
	cout << "a1 front: " << a1.front() << endl;
	cout << "a1 back: " << a1.back() << endl;
	
	array<int, 5>::iterator it1 = min_element(a1.begin(), a1.end());
	cout << "a1 minimum: " << *it1 << endl;
	
	array<int, 5>::iterator it2 = max_element(a1.begin(), a1.end());
	cout << "a1 maximum: " << *it2 << endl;
	
	auto it3 = adjacent_find(a1.begin(), a1.end());
	if(it3 != a1.end()) cout << "Adjacent element found in a1. " << *it3 << endl;
	
	int i1 = accumulate(a1.begin(), a1.end(), 0);
	cout << "a1 sum of elements: " << i1 << endl;
	
	int i2 = count(a1.begin(), a1.end(), 3);
	cout << "a1 count of 3: " << i2 << endl;
	
	int i3 = count_if(a1.begin(), a1.end(), [](int x){return x < 4;});
	cout << "a1 count of numbers smaller than 4: " << i3 << endl;
	cout << "----------------------------------------------" << endl;
	
	cout << "Contents of array a1: ";
	Display(a1);
	a1[4] = 6; //boundary not checked.
	cout << "a1[4] = 6 -> Contents of array a1: ";
	Display(a1);
	cout << "----------------------------------------------" << endl;
	
	cout << "Contents of array a2: ";
	Display(a2);
	a2.at(4) = 60; //boundary checked.
	cout << "a2.at(4) = 60 -> Contents of array a2: ";
	Display(a2);
	cout << "----------------------------------------------" << endl;
	
	//overwrite values of a2 to a1.
	cout << "Before Swap -> a1: ";
	Display(a1);
	a1.swap(a2);
	cout << "After Swap -> a1: ";
	Display(a1);
	cout << "----------------------------------------------" << endl;
	
	cout << "Before Fill -> a2: ";
	Display(a2);
	a2.fill(0);
	cout << "After Fill -> a2: ";
	Display(a2);
	cout << "----------------------------------------------" << endl;
	
    int *p1 = a1.data(); //pointer to array container.
	cout << "Contents of array a1: ";
	Display(a1);
	cout << "Pointer to Container a1:  " << p1 << endl;
	*p1 = 1;
	cout << "*p1 = 1 -> Contents of array a1: ";
	Display(a1);
	cout << "----------------------------------------------" << endl;
	
	//sort array.
	a1 = {5, 7, 8, 9, 6};
	cout << "Before Sort -> a1: ";
	Display(a1);
	sort(a1.begin(), a1.end());
	cout << "After Sort -> a1: ";
	Display(a1);
	cout << endl;

	return 0;
}