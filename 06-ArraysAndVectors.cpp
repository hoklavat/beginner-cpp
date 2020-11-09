//06-ArraysandVectors

#include <iostream>
#include <vector>
using namespace std;

int main(){
	//int a1[5]; //junk initialization
	//int a1[5]{}; //zero initialization
	int a1[5]{10, 20, 30}; //user initialization
	int a2[3][3]//multi-dimensional array, row-column, 2-dimensional array is called matrice.
	{{1, 2, 3},
	 {4, 5, 6}, 
	 {7, 8, 9}
	};
	
	//vector: class for array operations.
	vector<int> v1{10, 20, 30}; //one-dimensional vector of int type. 
	vector <vector <int>> v2 //two-dimensional vector (matrice) of int type.
	{{1, 2, 3},
	 {4, 5, 6},
	 {7, 8, 9}
	};
	
	cout << "a1 = " << a1 << endl; //address of first element of array.
	cout << "a1[2] = " << a1[2] << endl; //value of third element of array.
	cout << "a1[3] = " << a1[3] << endl; //value of fourth element of array.
	cout << "a2[1][1] = " << a2[1][1] << endl; //value of element at 1st row and 1st column of two-dimensional array.
	cout << "v1[1] = " << v1[1] << endl; //value of second element of vector.
	cout << "v1.at(1) = " << v1.at(1) << endl; //value at specific position. [1] = .at(1)
	v1.push_back(40); //add element at the end of vector. vector is dynamically resized.
	cout << "v1.at(3) = " << v1.at(3) << endl; //value of fourth element of vector.
	cout << "v1.size() = " << v1.size() << endl; //number of elements in the vector.
	cout << "v2[1][1] = " << v2[1][1] << endl; //value of element at 1st row and 1st column of two-dimensional vector.
	cout << "v2.at(1).at(1) = " << v2.at(1).at(1) << endl; //same as above.
	
	return 0;
}