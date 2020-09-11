//54- Standart Template Library (Containers - Stack)

#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;

template <typename T>
void Display(stack<T> s){
	cout << "[ ";
	while(!s.empty()){
		T e = s.top();
		s.pop();
		cout << e << " ";
	}
	cout << "]" << endl;
}

int main(){
	stack<int> s1; //stack<int, deque> s1;
	stack<int, vector<int>> s2;
	stack<int, list<int>> s3;
	
	for(int i: {1, 2, 3, 4, 5})
		s1.push(i);
	
	Display(s1);
	s1.push(100);
	Display(s1);
	s1.top() = 50;
	Display(s1);
	s1.pop();
	Display(s1);
	
	while(!s1.empty()){		
		cout << "Size: " << s1.size() << " - ";
		Display(s1);
		s1.pop();
	}

	return 0;
}
