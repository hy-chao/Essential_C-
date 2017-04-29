/*
*C++��ϰ�⣺Essential C++ ������
*author��hyc
*date��2017.4.29
*/
#include<iostream>
#include<string>
#include<exception>

using namespace std;

//��ϰ7.1
/*
int *alloc_and_init(string file_name)
{
	char ss;
	ifstream infile(file_name);   //"�ͱ𲻷�"
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
//��ϰ7.2
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
	//���û���쳣���׳�������ͻ�ִ�е����
	return pi;
}
*/
//��ϰ7.3
//����PopOnEmpty()��PushOnFull()�����쳣�࣬�ֱ�pop()��push()�׳���
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