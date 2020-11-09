//54-StandartTemplateLibrary(Containers-Stack)

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
	stack<int> s1; //stack<int, deque> s1; //default stack type is deque.
	cout << "s1: ";
	Display(s1);
	for(int i: {1, 2, 3, 4, 5})
		s1.push(i);
	cout << "After Push Operations -> s1: ";
	Display(s1);
	s1.push(100);
	cout << "s1.push(100) -> s1: ";
	Display(s1);
	s1.top() = 50;
	cout << "s1.top() = 50 -> s1: ";
	Display(s1);
	s1.pop();
	cout << "s1.pop() -> s1: ";
	Display(s1);
	while(!s1.empty()){	
		s1.pop();	
		cout << "Pop -> Size: " << s1.size() << endl;		
	}
	
	stack<int, vector<int>> s2;
	for(int i: {1, 2, 3, 4, 5})
		s2.push(i);
	cout << "Vector Stack -> ";
	cout << "s2.top(): " << s2.top() << endl;
	
	stack<int, list<int>> s3;
	for(int i: {1, 2, 3, 4, 5})
		s3.push(i);
	cout << "List Stack -> ";
	cout << "s3.top(): " << s3.top() << endl;
	
	return 0;
}