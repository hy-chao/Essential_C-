/*
*C++Á·Ï°Ìâ£ºEssential C++ µÚ¶þÕÂ
*author£ºhyc
*date£º2017.4.7
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
// Á·Ï°2.2
vector<int> PentagonalInit(vector<int>& a, int n)
{
	if (n < 1 || n > 1024)
	{
		cerr << "stackooooooooooooooooverflow!!!" << endl;
		return a;
	}
	for (int i = 1; i < n + 1; i++)
	{
		a.push_back(i*(3*i-1)/2);
	}
	return a;
}
vector<int> PentagonalInit_pointer(vector<int> a, int n)
{

	if (n < 1 || n > 1024)
	{
		cerr << "stackooooooooooooooooverflow!!!" << endl;
		return a;
	}
	for (int i = 1; i < n + 1; i++)
	{
		a.push_back(i*(3 * i - 1) / 2);
	}
	return a;
}
void display(vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
}
int main()
{
	vector<int> a ;
	int n = 10;
	a = PentagonalInit_pointer(a, n);
	display(a);
	return 0;
}
*/
/*
//Á·Ï°2.3
inline bool is_size_ok(int size)
{
	const int max_size = 1024;
	if (size <= 0 || size > max_size)
	{
		cerr << "Oops: requested size is not supported: "
			<< size << "-- can't fullfill request.\n";
		return false;
	}
	return true;
}
vector<int> PentagonalInit_pointer(vector<int> &a, int n)
{
	if (!is_size_ok(n))
	{
		return a;
	}
	for (int i = a.size()+1; i < n + 1; i++)
	{
		a.push_back(i*(3 * i - 1) / 2);
	}
	return a;
}

void display(vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
}

int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(5);
	int n = 10;
	a = PentagonalInit_pointer(a, n);
	display(a);
	return 0;
}
*/

/*
//Á·Ï°2.4
const vector<int>* PentagonalInit(int size)
{
	static vector<int> a;
	if (a.size() < size)
	{
		for (int i = a.size() + 1; i < size + 1; i++)
		{
			a.push_back(i*(3 * i - 1) / 2);
		}
	}
	
	return &a;
}
int recall_single_elem(const vector<int>* a, int n)
{
	if (n >= a->size())
	{
		cerr << "input error!" << endl;
		return -1;
	}
	return (*a)[n];
}

int main()
{
	const vector<int> *a = PentagonalInit(10);
	cout << recall_single_elem(a, 3);
	return 0;
}
*/

/*
//Á·Ï°2.5
void max(int a, int b)
{
	if (a < b)
	{
		cout << b << endl;
	}
	else
	{
		cout <<  a << endl;
	}
}

void max(float a, float b)
{
	if (a < b)
	{
		cout <<  b << endl;
	}
	else
	{
		cout <<  a << endl;
	}
}

void max(char* a, char* b)
{
	if (strcmp(a, b) > 0)
	{
		cout <<  a << endl;
	}
	else
	{
		cout <<  b << endl;
	}
}

void max(vector<int> a)
{
	int re = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (re < a[i])
		{
			re = a[i];
		}
	}
	cout << re << endl;
}
void max(vector<float> a)
{
	float re = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (re < a[i])
		{
			re = a[i];
		}
	}
	cout << re << endl;
}
void max(vector<char*> a)
{
	char* re = NULL;
	for (int i = 0; i < a.size(); i++)
	{
		if (re < a[i])
		{
			re = a[i];
		}
	}
	cout << re << endl;
}

int main()
{
	max(1, 3);
	max(1.2f, 1.5f);
	max("adda","adfas");
	vector<int> a = {2, 4};
	vector<float> b = {2.3f, 2.5f};
	vector<char*> c = {"sdad", "sdadsd"};
	max(a);
	max(b);
	max(c);
	return 0;
}
*/
/*
//Á·Ï°2.6
template <typename elemType >
void max(elemType a, elemType b)
{
	if (a < b)
	{
		cout << b << endl;
	}
	else
	{
		cout << a << endl;
	}
}
template <typename elemType >
void max(vector<elemType> a)
{
	elemType re = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (re < a[i])
		{
			re = a[i];
		}
	}
	cout << re << endl;
}
int main()
{
	max(1, 3);
	max(1.2f, 1.5f);
	max("adda", "adfas");
	vector<int> a = { 2, 4 };
	vector<float> b = { 2.3f, 2.5f };
	vector<char*> c = { "sdad", "sdadsd" };
	max(a);
	max(b);
	max(c);
	return 0;
}
*/

