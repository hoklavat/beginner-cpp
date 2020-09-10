//11- Random Numbers

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	srand(time(nullptr)); //seed number
	//srand(10); //fixed seed number generates same number
	cout << "RAND_MAX = " << RAND_MAX << endl;
	cout << "random number between 0 and RAND_MAX = "<< rand() << endl;
	cout << "random number between 5 and 55 = "<< (rand() % 50 + 5) << endl;	
	return 0;
}
