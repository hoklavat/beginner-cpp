//11-RandomNumbers

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	srand(time(nullptr)); //seed with dynamic variable which in case time.
	//srand(10); //fixed seed generates same number
	cout << "RAND_MAX = " << RAND_MAX << endl; //maximum random number that can be produced. 32767.
	cout << "Random number between 0 and RAND_MAX = "<< rand() << endl; //generate random number. min:0, max:RAND_MAX
	cout << "Random number between 5 and 55 = "<< (rand() % 50 + 5) << endl; //generate random number between limits.
	return 0;
}
