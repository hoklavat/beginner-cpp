//55- Standart Template Library (Containers - Queue)

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
	queue<int> q1;
	
	for(int i: {1, 2, 3, 4, 5})
		q1.push(i);
	
	Display(q1);
	cout << "Front: " << q1.front() << endl;
	cout << "Back: " << q1.back() << endl;
	q1.push(6);
	Display(q1);
	q1.front() = 0;
	q1.back() = 10;
	Display(q1);
	
	while(!q1.empty()){
		q1.pop();
		cout << "Size: " << q1.size() << " - ";
		Display(q1);
	}

	return 0;
}
