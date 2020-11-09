//55-StandartTemplateLibrary(Containers-Queue)

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
void Display(queue<T> q){
	cout << "[ ";
	while(!q.empty()){
		T e = q.front();
		q.pop();
		cout << e << " ";
	}
	cout << "]" << endl;
}

int main(){
	queue<int> q;
	
	for(int i: {1, 2, 3, 4, 5})
		q.push(i);
	
	cout << "q: ";
	Display(q);
	cout << "q.front(): " << q.front() << endl;
	cout << "q.back(): " << q.back() << endl;
	q.push(6);
	cout << "q.push(6) -> q: ";
	Display(q);
	q.front() = 0;
	cout << "q.front() = 0 -> q: ";
	Display(q);
	q.back() = 10;
	cout << "q.back() = 10 -> q: ";
	Display(q);
	
	while(!q.empty()){
		q.pop();
		cout << "q.pop() -> Size: " << q.size() << ", q: ";
		Display(q);
	}

	return 0;
}