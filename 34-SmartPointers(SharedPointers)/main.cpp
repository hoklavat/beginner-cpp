//34- Smart Pointers (Shared Pointers)

#include <iostream>
#include <memory>
using namespace std;

int main(){
	shared_ptr<int> s1 = make_shared<int>(100); 
	//shared_ptr<int> s1{new int{100}};
	shared_ptr<int> s2{s1};
	shared_ptr<int> s3;
	s3 = s2;
	
	cout << *s1 << ", " << s1.get() << endl;
	cout << *s2 << ", " << s2.get() << endl;
	cout << *s3 << ", " << s3.get() << endl;	
	cout << "Count: " << s1.use_count() << endl;
	s3.reset();
	cout << "Count: " << s1.use_count() << endl;	
	cout << endl;

	return 0;
}
