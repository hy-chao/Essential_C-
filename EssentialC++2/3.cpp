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

//练习3.2
