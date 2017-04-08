/*
*C++练习题：Essential C++ 第三章
*author：hyc
*date：2017.4.8
*/
#include<iostream>
#include<string>
#include <fstream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<functional>
#include<iterator>
using namespace std;

/*
//练习3.1
void Read_Data(map<string, int> &a)
{
	ifstream fin("data.txt");
	string s;
	string bb[] = {"a", "an", "or", "the", "and", "but"};
	set<string> b(bb,bb+6);
	while (fin >> s)
	{
		if (b.count(s))
			continue;
		a[s]++;
	}
}
int main()
{
	map<string, int> words;
	Read_Data(words);
	cout << "输入要查询的单词:";
	string word_check;
	cin >> word_check;
	if (words.count(word_check) > 0)
	{
		cout << words[word_check] << endl;
	}
	else
	{
		cout << "不存在！" << endl;
	}
	map<string, int>::iterator it = words.begin();
	for (; it != words.end(); it++)
	{
		cout << "word: " << it->first << "     "
			<< "value: " << it->second << endl;
	}
	return 0;
}
*/
/*
//练习3.2
class LessThan 
{
public:
	bool operator()(const string & s1, const string & s2)
	{
		return s1.size() < s2.size();
	}
};
void Read_Data(vector<string> &a)
{
	ifstream fin("data.txt");
	string s;
	string bb[] = { "a", "an", "or", "the", "and", "but" };
	set<string> b(bb, bb + 6);
	while (fin >> s)
	{
		if (b.count(s))
			continue;
		a.push_back(s);
	}
	sort(a.begin(), a.end(), LessThan());
}

int main()
{
	vector<string> a;
	Read_Data(a);
	vector<string>::iterator it = a.begin();
	for (; it != a.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}
*/
/*
//练习3.3
void display(map<string, vector<string> > &a)
{
	for (int i = 0; i < 6; i++)
	{
		string x, m;
		cin >> x >> m;
		a[x].push_back(m);
	}
	map<string, vector<string> >::iterator it = a.begin();
	for (; it != a.end(); it++)
	{
		int num = it->second.size();
		while (num > 0)
		{
			cout << it->first << it->second[num-1] << endl;
			num--;
		}
			
	}
}
int main()
{
	map<string, vector<string> > a;
	display(a);
	string find;
	cin >> find;
	vector<string>::iterator it = a[find].begin();
	for (; it != a[find].end(); it++)
	{
		cout << find << *it << endl;
	}
	
	return 0;
}
*/
/*
//练习3.4
void io_stream_display()
{
	vector<int> a;
	istream_iterator<int> is(cin);
	istream_iterator<int> eof;
	copy(is, eof, back_inserter(a));
	vector<int>::iterator it = a.begin();
	vector<int> js;
	vector<int> bu;
	for (; it != a.end(); it++)
	{
		if (((*it) % 2) == 0)
		{
			bu.push_back(*it);
		}
		else
		{
			js.push_back(*it);
		}
	}
	ofstream out_file1("data1.txt");
	ofstream out_file2("data2.txt");
	ostream_iterator<int> os1(out_file1, " ");
	ostream_iterator<int> os2(out_file2, " ");
	copy(js.begin(), js.end(), os1);
	copy(bu.begin(), bu.end(), os2);
}

int main()
{
	io_stream_display();
	return 0;
}
*/