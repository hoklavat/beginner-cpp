#include "Test.h"

int Test::Count{0};

Test::Test(){
	Count++;
}

Test::~Test(){
	Count--;
}

int Test::GetCount(){
	return Count;
}

