/*
*C++练习题：Essential C++ 第七章
*author：hyc
*date：2017.4.29
*/
#include<iostream>
#include<string>
#include<exception>

using namespace std;

//练习7.1
/*
int *alloc_and_init(string file_name)
{
	char ss;
	ifstream infile(file_name);   //"型别不符"
	int elem_cnt;
	infile >> elem_cnt;
	int *pi = allocate_array(elem_cnt);

	int elem;
	int index = 0; 
	while (infile >> elem)
	{
		pi[index++] = elem;
	}
	sort_array(pi, elem_cnt);
	register_data(pi);

	return pi;
}
*/
//练习7.2
/*
int *alloc_and_init(string file_name)
{
	char ss;
	ifstream infile(file_name.c_str());   
	int elem_cnt;
	infile >> elem_cnt;
	if (!infile)
		return 0;
	try
	{
		int *pi = allocate_array(elem_cnt);
		int elem;
		int index = 0;
		while (infile >> elem)
		{
			pi[index++] = elem;
		}
		sort_array(pi, elem_cnt);
		register_data(pi);
	}
	catch (const noMem &memFail)
	{
		cerr << "1" << endl;
		return 0;
	}
	catch (int &sortFail)
	{
		cerr << "2" << endl;
		return 0;
	}
	catch (string &registerFail)
	{
		cerr << "3" << endl;
		return 0;
	}
	//如果没有异常被抛出，程序就会执行到这里。
	return pi;
}
*/
//练习7.3
//定义PopOnEmpty()和PushOnFull()两个异常类，分别供pop()和push()抛出。
/*
void pop(elemType &elem)
{
	if (empty())
		throw PopOnEmpty();
	elem = _stack[--top];
	_stack.pop_back();
}

void push(const elemType &elem)
{
	if (!full())
	{
		_stack.push_back(elem);
		++_top;
		return;
	}
	throw PushOnFull();
}
*/