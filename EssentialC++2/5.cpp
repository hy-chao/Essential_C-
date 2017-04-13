/*
*C++��ϰ�⣺Essential C++ ������
*author��hyc
*date��2017.4.13
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;
//��ϰ5.1
class Stack
{
public:
	virtual void pop() = 0;
	virtual void push(int) = 0;
	virtual int size()
	{
		return _stack.size();
	}
	virtual bool empty()
	{
		return _stack.size() == 0;
	}

private:
	vector<int> _stack;
};