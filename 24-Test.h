#ifndef _TEST_H //used to ensure that this class has not declared before. #pragma once do the same job.
#define _TEST_H

//Declaration of Class

class Test{
private:
	static int Count;
public:
	Test();
	~Test();
	static int GetCount();	
};

#endif // _TEST_H
