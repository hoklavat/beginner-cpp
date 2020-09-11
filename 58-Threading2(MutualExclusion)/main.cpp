//58- Threading 2 (Mutual Exclusion)
/***************************************************************************************
- mutex library prevents simultaneous access to shared data by threads

- Involved
 * mingw.mutex.h => mutex library
 * std::mutex => mutex class
 * lock() => lock access to data
 * unlock() => unlock access to data
/****************************************************************************************/

#include "mingw.thread.h"
#include "mingw.mutex.h"

#include <iostream>
#include <chrono>

std::mutex m1;
int n1 = 0;  //protected by m1
 
void Increment(){
	while(n1 < 10){
		m1.lock(); //lock n1 until unlock
		n1++;
		std::cout << "n1 = " << n1 << std::endl;
		m1.unlock();
		std::this_thread::sleep_for(std::chrono::seconds(1));	
	}	
}

void Reset(int x){
	int c{0};
	while(true){
		std::this_thread::sleep_for(std::chrono::seconds(5)); //reset after each 5 seconds
		c++;
		if(c == x) break;
		if(n1 > 0) n1 = 0;
	}
}
 
int main(){
	std::thread t1(Increment);
	std::thread t2(Reset, 3); //reset 3 times
	t1.join();
	t2.join();
}
