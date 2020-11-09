//24- Class 4 (Static)

#include <iostream>
#include "24-Test.h" //class declared in .h, implemented in .cpp
using namespace std;

int main(){
	Test *t1 = {new Test}; //Count = 1
	Test *t2 = {new Test}; //Count = 2
	Test *t3 = {new Test}; //Count = 3
	Test *t4 = {new Test}; //Count = 4
	
	cout << "Test::GetCount() = " << Test::GetCount() << endl; //4
	delete t4;
	cout << "Test::GetCount() = " << Test::GetCount() << endl; //3
	cout << endl;
	
	return 0;
}