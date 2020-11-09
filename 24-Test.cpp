#include "24-Test.h"

//Implementation and Initialization of Class Members

Test::Test(){
	Count++;
}

Test::~Test(){
	Count--;
}

int Test::GetCount(){
	return Count;
}

int Test::Count{0};

