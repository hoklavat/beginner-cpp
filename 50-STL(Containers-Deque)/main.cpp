//50- Standart Template Library (Containers - Deque)

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
	deque<int> d2(5, 1);
	vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	Display(d1);
	Display(d2);
	d2.at(2) = 3;
	d2[4] = 5;
	Display(d2);
	d2.push_back(6);
	Display(d2);
	d2.push_front(0);
	Display(d2);
	d2.pop_back();
	Display(d2);
	d2.pop_front();
	Display(d2);
	
	cout << "d1 size:" << d1.size() << endl;
	cout << "d1 front:" << d1.front() << endl;
	cout << "d1 back:" << d1.back() << endl;
	
	d1.clear();
	copy(v1.begin(), v1.end(), front_inserter(d1));
	Display(d1);
	d1.clear();
	copy(v1.begin(), v1.end(), back_inserter(d1));
	Display(d1);	

	return 0;
}
