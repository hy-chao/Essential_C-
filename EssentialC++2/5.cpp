/*
*C++Á·Ï°Ìâ£ºEssential C++ µÚÎåÕÂ
*author£ºhyc
*date£º2017.4.13
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;
//Á·Ï°5.1
/*
class Stack
{
public:
	virtual ~Stack() {}
	virtual bool pop(int &) = 0;
	virtual bool push(const int&) = 0;
	virtual bool peek(int index, int &) = 0;

	virtual int top() const = 0;
	virtual int size() const = 0;
	virtual bool empty() const = 0;
	virtual bool full() const = 0;

	virtual void print( ostream& = cout ) const = 0;
};
ostream& operator << (ostream &os, const Stack &rhs)
{
	rhs.print();
	return os;
}
class LIFO_Stack : public Stack
{
public:
	LIFO_Stack(int cap = 0) : _top(0)
	{
		if (cap)
		{
			_stack.reserve(cap);
		}
	}
	
	virtual int size() const
	{
		return _stack.size();
	}
	virtual bool empty() const
	{
		return _stack.size();
	} 
	virtual bool full() const 
	{
		return size() >= _stack.max_size();
	}
	virtual int top() const
	{
		return _top;
	}
	virtual void print(ostream &os = cout) const;

	virtual bool pop( int & );
	virtual bool push( const int & );
	virtual bool peek(int, int &)
	{
		return false;
	}
private:
	vector<int> _stack;
	int _top;
};

bool LIFO_Stack::pop(int &elem) 
{
	if (empty())
		return false;
	elem = _stack[ --_top ];
	_stack.pop_back();
	return true;
}

bool LIFO_Stack::push(const int & elem)
{
	if (full())
	{
		return false;
	}
	_stack.push_back(elem);
	++_top;
	return true;
}

void LIFO_Stack::print(ostream &os) const
{
	vector<int> ::const_reverse_iterator rit = _stack.rbegin();
	vector<int> ::const_reverse_iterator rend = _stack.rend();

	os << "\n\t";
	while (rit != rend)
	{
		os << *rit++ << "\n\t";
	}
	os << endl;
}

class Peekback_Stack : public Stack
{
public:
	Peekback_Stack(int cap = 0) : _top(0)
	{
		if (cap)
		{
			_stack.reserve(cap);
		}
	}

	virtual int size() const
	{
		return _stack.size();
	}
	virtual bool empty() const
	{
		return _stack.size();
	}
	virtual bool full() const
	{
		return size() >= _stack.max_size();
	}
	virtual int top() const
	{
		return _top;
	}
	virtual void print(ostream &os = cout) const;

	virtual bool pop(int &);
	virtual bool push(const int &);
	virtual bool peek(int, int &);
private:
	vector<int> _stack;
	int _top;
};

bool Peekback_Stack::peek(int index, int & elem)
{
	if (empty())
		return false;
	if (index < 0 || index > size())
		return false;
	elem = _stack[index];
	return true;
}
bool Peekback_Stack::pop(int &elem)
{
	if (empty())
		return false;
	elem = _stack[--_top];
	_stack.pop_back();
	return true;
}

bool Peekback_Stack::push(const int & elem)
{
	if (full())
	{
		return false;
	}
	_stack.push_back(elem);
	++_top;
	return true;
}

void Peekback_Stack::print(ostream &os) const
{
	vector<int> ::const_reverse_iterator rit = _stack.rbegin();
	vector<int> ::const_reverse_iterator rend = _stack.rend();

	os << "\n\t";
	while (rit != rend)
	{
		os << *rit++ << "\n\t";
	}
	os << endl;
}

void peek(Stack &st, int index)
{
	cout << endl;
	int t;
	if (st.peek(index, t))
	{
		cout << "peek: " << t;
	}
	else
	{
		cout << "peek failed!";
	}
	cout << endl;
}

int main()
{
	LIFO_Stack st;
	int s;
	while (cin >> s && !st.full())
		st.push(s);
	cout << '\n' << "About to call peek() with LIFO_Stack" << endl;
	peek(st, st.top() - 1);
	cout << st;

	Peekback_Stack pst;
	while (!st.empty())
	{
		int t;
		if (st.pop(t))
			pst.push(t);
	}
	cout << '\n' << "About to call peek() with Peekback_Stack" << endl;
	peek(pst, pst.top() - 1);
	cout << pst;
}
*/
//Á·Ï°5.2

class Stack
{
public:
	Stack(int cap = 0) : _top(0)
	{
		if (cap)
		{
			_stack.reserve(cap);
		}
	}
	virtual ~Stack() {}
	int size() const
	{
		return _stack.size();
	}
	bool empty() const
	{
		return _stack.size();
	}
	bool full() const
	{
		return size() >= _stack.max_size();
	}
	int top() const
	{
		return _top;
	}
	void print(ostream &os = cout) const;

	bool pop(int &);
	bool push(const int &);
	virtual bool peek(int, int &)
	{
		return false;
	}
protected:
	vector<int> _stack;
	int _top;
};

bool Stack::pop(int &elem)
{
	if (empty())
		return false;
	elem = _stack[--_top];
	_stack.pop_back();
	return true;
}

bool Stack::push(const int & elem)
{
	if (full())
	{
		return false;
	}
	_stack.push_back(elem);
	++_top;
	return true;
}

void Stack::print(ostream &os) const
{
	vector<int> ::const_reverse_iterator rit = _stack.rbegin();
	vector<int> ::const_reverse_iterator rend = _stack.rend();

	os << "\n\t";
	while (rit != rend)
	{
		os << *rit++ << "\n\t";
	}
	os << endl;
}
//ÖØÔØ<<ÔËËã·û
ostream& operator << (ostream &os, const Stack &rhs)
{
	rhs.print();
	return os;
}

class Peekback_Stack : public Stack
{
public:
	Peekback_Stack(int cap = 0) : Stack(cap)
	{}

	virtual bool peek(int index, int &elem);
};

bool Peekback_Stack::peek(int index, int & elem)
{
	if (empty())
		return false;
	if (index < 0 || index > size())
		return false;
	elem = _stack[index];
	return true;
}

void peek(Stack &st, int index)
{
	cout << endl;
	int t;
	if (st.peek(index, t))
	{
		cout << "peek: " << t;
	}
	else
	{
		cout << "peek failed!";
	}
	cout << endl;
}

int main()
{
	Peekback_Stack st;
	int s;
	while (cin >> s && !st.full())
		st.push(s);
	cout << '\n' << "About to call peek() with LIFO_Stack" << endl;
	peek(st, st.top() - 1);
	cout << st;
	
	return 0;
}