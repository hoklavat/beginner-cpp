//06- Arrays and Vectors

#include <iostream>
#include <vector>
using namespace std;

int main(){
	//int a1[5]; //initialization: junk values
	//int a1[5]{}; //initialization: zeros
	int a1[5]{10, 20, 30}; //initialization: user-defined
	int a2[3][3]//multi-dimensional, row-column 
	{{1, 2, 3},
	 {4, 5, 6}, 
	 {7, 8, 9}
	};
	
	vector <int> v1{10, 20, 30};
	vector <vector <int>> v2
	{{1, 2, 3},
	 {4, 5, 6},
	 {7, 8, 9}
	};
	
	cout << "a1 = " << a1 << endl; //address of first element
	cout << "a1[2] = " << a1[2] << endl;
	cout << "a1[3] = " << a1[3] << endl;
	cout << "a2[1][1] = " << a2[1][1] << endl;
	cout << "v1[1] = " << v1[1] << endl;
	cout << "v1.at(1) = " << v1.at(1) << endl; //[1] = .at(1)
	v1.push_back(40); //add element at end
	cout << "v1.at(3) = " << v1.at(3) << endl;
	cout << "v1.size() = " << v1.size() << endl; //number of elements
	cout << "v2[1][1] = " << v2[1][1] << endl;
	cout << "v2.at(1).at(1) = " << v2.at(1).at(1) << endl;	
	return 0;
}
