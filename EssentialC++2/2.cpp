/*
	C++Á·Ï°Ìâ£ºEssential C++ µÚ¶þÕÂ
	author£ºhyc
	date£º2017.4.7
*/
#include<iostream>
#include<vector>
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
