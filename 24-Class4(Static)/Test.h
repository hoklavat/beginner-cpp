#ifndef _TEST_H
#define _TEST_H

class Test{
private:
	static int Count;
public:
	Test();
	~Test();
	static int GetCount();	
};

#endif // _TEST_H
