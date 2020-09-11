//57- Threading 1 (Synchronous Threads)
/***************************************************************************************
- thread = function to be joined in threading pool.
- standard thread library won't work on mingw gcc
- obtain mingw.thread library from https://github.com/meganz/mingw-std-threads
- put headers in same folder of main.cpp
- delete following line in mingw.thread.h if you get thaterror
 * #error To use the MinGW-std-threads library, you will need to define the macro _WIN32_WINNT to be 0x0501 (Windows XP) or higher.

- Involved
 * std::this_thread::sleep_for(std::chrono::miliseconds(x)) >> stop thread x milisecs
 * std:thread(function, arguments) >> main thread class, function to thread
 * join >> add thread to pool
/****************************************************************************************/

#include "mingw.thread.h"

#include <iostream>
#include <utility>
#include <chrono>
#include <stdlib.h>

int c1{0}, c2{0}, c3{0}, c4{0}; //counter for each thread

void Thread1(int n){
	for (int i = 0; i < 20; i++){ //total 20secs
		c1++;
		system("CLS");
		std::cout << "Thread 1: " << c1 << " - " << "Thread 2: " <<  c2 << " - " << "Thread 3: " <<  c3 << " - " << "Thread 4: " <<  c4 << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //1 second, 20 times
	}
}

void Thread2(int &n){
	for (int i = 0; i < 10; i++){
		c2++;
		std::this_thread::sleep_for(std::chrono::milliseconds(2000)); //2 second, 10 times
	}
}
 
class Class1{
public:
	int n{0};
    void Thread3(){
		for (int i = 0; i < 5; ++i){			
			c3++;
			std::this_thread::sleep_for(std::chrono::milliseconds(4000)); //4 second, 5 times
		}
	}
};
 
class Class2{
public:
	void operator()(){
		for (int i = 0; i < 2; ++i){
			c4++;
			std::this_thread::sleep_for(std::chrono::milliseconds(10000)); //10 second, 2 times
		}
	}
};
 
int main(){
	int n = 0;
	Class1 c1;
	Class2 c2;
	std::thread t1; //empty thread
	std::thread t2(Thread1, 10); //pass by value
	std::thread t3(Thread2, std::ref(n)); //pass by reference
	std::thread t4(std::move(t3)); // t4 is now running Thread2(). t3 is no longer a thread
	std::thread t5(&Class1::Thread3, &c1); // t5 runs Thread3 on object c1
	std::thread t6(c2); // t6 runs Class2::operator() on object c2
	t2.join();
	t4.join();
	t5.join();
	t6.join();
}
