//50-StandartTemplateLibrary(Containers-Deque)

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void Display(const deque<T> &d){
	cout << "[ ";
	for(const auto &e: d)
		cout << e << " ";
	cout << "]" << endl;
}

int main(){
	
	deque<int> d1{1, 2, 3, 4, 5};
	cout << "d1: ";
	Display(d1);
	cout << "d1.size:" << d1.size() << endl;
	cout << "d1.front:" << d1.front() << endl;
	cout << "d1.back:" << d1.back() << endl;
	
	vector<int> v{10, 20, 30, 40, 50, 60, 70, 80, 90};
	cout << "v: ";
	for(auto &e: v)
		cout << e << " ";
	cout << endl;
	
	cout << "d1: ";
	Display(d1);
	d1.clear();
	copy(v.begin(), v.end(), front_inserter(d1));
	cout << "After Front Insertion -> d1: ";
	Display(d1);	
	d1.clear();
	copy(v.begin(), v.end(), back_inserter(d1));
	cout << "After Back Insertion -> d1: ";
	Display(d1);
	
	deque<int> d2(5, 1);
	cout << "d2: ";
	Display(d2);	
	d2.at(2) = 3;
	cout << "d2.at(2) = 3 -> d2: ";
	Display(d2);
	d2[4] = 5;
	cout << "d2[4] = 5 -> d2: ";
	Display(d2);
	
	d2.push_back(6);
	cout << "d2.push_back(6) -> d2: ";
	Display(d2);
	d2.push_front(0);
	cout << "d2.push_front(0) -> d2: ";
	Display(d2);
	d2.pop_back();
	cout << "d2.pop_back() -> d2: ";
	Display(d2);
	d2.pop_front();
	cout << "d2.pop_front() -> d2: ";
	Display(d2);
	
	return 0;
}