//24- Class 4 (Static)

#include <iostream>
#include "Test.h"
using namespace std;

int main(){
	Test *t1 = {new Test};
	Test *t2 = {new Test};
	Test *t3 = {new Test};
	Test *t4 = {new Test};
	
	cout << "Count: " << Test::GetCount() << endl;
	delete t4;
	cout << "Count: " << Test::GetCount() << endl;
	cout << endl;
	return 0;
}
