//34-SmartPointers(SharedPointers)
//shared pointers can point to same location.

#include <iostream>
#include <memory>
using namespace std;

int main(){
	shared_ptr<int> s1 = make_shared<int>(100); //shared_ptr<int> s1{new int{100}};
	shared_ptr<int> s2{s1};
	shared_ptr<int> s3;
	s3 = s2;
	
	cout << "s1 Value = " << *s1 << ", s1 Address = " << s1.get() << endl;
	cout << "s2 Value = " << *s2 << ", s2 Address = " << s2.get() << endl;
	cout << "s3 Value = " << *s3 << ", s3 Address = " << s3.get() << endl;
	
	cout << endl << "Count: " << s1.use_count() << endl; //use_count: how many pointers have access?
	s3.reset(); //s3 is disposed.
	cout << "Count after resetting s3: " << s1.use_count() << endl;	

	return 0;
}