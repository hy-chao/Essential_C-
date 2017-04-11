/*
*C++练习题：Essential C++ 第四章
*author：hyc
*date：2017.4.9
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

//练习4.1 &&练习4.2
/*
class stack
{
public:
	bool push(const string &);
	bool pop(string &elem);
	bool peek(string &elem);
	bool find(string elem) const;
	int count(string elem) const;
	bool empty();
	bool full();
	int size()
	{
		return _stack.size();
	}
private:
	vector<string> _stack;
};
bool stack::push(const string &a)
{
	if (!this->full())
	{
		_stack.push_back(a);
		return true;
	}
	return false;
}
bool stack::pop(string &elem)
{
	if (!this->empty())
	{
		elem = _stack.back();
		_stack.pop_back();
		return true;
	}
	return false;
}
bool stack::peek(string &elem) // 取得栈顶数据，不弹栈
{
	if (!this->empty())
	{
		elem = _stack.back();
		return true;
	}
	return false;
}
bool stack::find(string elem) const
{
	if (!this->empty())
	{
		vector<string>::iterator it = _stack.begin();
		for (; it != _stack.end(); it++)
		{
			if (elem == *it)
			{
				return true;
			}
		}
	}
	return false;
}
int stack::count(string elem) const
{
	int num = 0;
	if (!this->empty())
	{
		vector<string>::iterator it = _stack.begin();
		for (; it != _stack.end(); it++)
		{
			if (elem == *it)
			{
				num++;
			}
		}
	}
	return num;
}
inline bool stack::full()
{
	return _stack.size() == _stack.max_size();
}
inline bool stack::empty()
{
	return _stack.empty();
}

int main()
{
	stack ss;
	string s;
	ss.push("a");
	cout << ss.size() << endl;
	ss.peek(s);
	cout << ss.size() << endl;
	cout << s << endl;
	ss.push("b");
	cout << ss.size() << endl;
	ss.pop(s);
	cout << ss.size() << endl;
	cout << s << endl;
	ss.peek(s);
	cout << s << endl;
	ss.push("b");
	ss.push("b");
	if (ss.find("a"))
	{
		cout << "hava 'a'" << endl;
	}
	cout << ss.count("b") << endl;
	return 0;
}
*/
//练习4.3
/*
封装全局变量的好处：
避免外界直接存取，只开放一小组函数作为对外接口。
更进一步，还可以因此将这些对象的名称隐藏于雷范围之内，不和其它全局实体发生名称上的冲突。
*/
/*
class Data_type
{
public:
	static string program_name()
	{
		return _program_name;
	}
	static string version_stamp()
	{
		return _version_stamp;
	}
	static int version_number()
	{
		return _version_number;
	}
	static int tests_run()
	{
		return _tests_run;
	}
	static int tests_passed()
	{
		return _tests_passed;
	}
	static void program_name(const string &a)
	{
		_program_name = a;
	}
	static void version_stamp(const string &a)
	{
		_version_stamp = a;
	}
	static void version_number(int a)
	{
		_version_number = a;
	}
	static void tests_run(int a)
	{
		_tests_run = a;
	}
	static int tests_passed(int a)
	{
		_tests_passed = a;
	}
private:
	static string  _program_name;
	static string _version_stamp;
	static int _version_number;
	static int _tests_run;
	static int _tests_passed;
};
*/
//练习4.4
/*
#include<map>
class UserProvide
{
public:
	enum ulevel { Beginner, Intermediate, Advanced, Guru };
	UserProvide();
	UserProvide(string login, ulevel = Beginner);
	bool operator==(const UserProvide&);
	bool operator!=(const UserProvide &rhs);
	//读取数据
	string login() const
	{
		return _login;
	}
	string user_name() const
	{
		return _user_name;
	}
	int login_count() const
	{
		return _times_logged;
	}
	int guess_count() const
	{
		return _guesses;
	}
	int guess_correct() const
	{
		return _correct_guesses;
	}
	double guess_average() const;
	string level() const;
	//写入数据
	void reset_login(const string &val)
	{
		_login = val;
	}
	void user_name(const string &val)
	{
		_user_name = val;
	}
	void reset_level(const string &);
	void reset_level(ulevel newlevel)
	{
		_user_level = newlevel;
	}
	void reset_login_count(int val)
	{
		_times_logged = val;
	}
	void reset_guess_count(int val)
	{
		_guesses = val;
	}
	void reset_guess_correct(int val)
	{
		_correct_guesses = val;
	}
	void bump_login_count(int cnt = 1)
	{
		_times_logged += cnt;
	}
	void bump_guess_count(int cnt = 1)
	{
		_guesses += cnt;
	}
	void bump_guess_correct(int cnt = 1)
	{
		_correct_guesses += cnt;
	}
private:
	string _login;
	string _user_name;
	int _times_logged;
	int _guesses;
	int _correct_guesses;
	ulevel _user_level;

	static map<string, ulevel> _level_map;
	static void init_level_map();
	static string guest_login();
};

inline double UserProvide::guess_average() const
{
	return _guesses ? double(_correct_guesses) / double(_guesses) * 100 : 0.0;
}
inline UserProvide::UserProvide(string login, ulevel level) : _login(login), _user_level(level), 
_times_logged(1), _guesses(0), _correct_guesses(0)
{}

#include<cstdlib>

inline UserProvide::UserProvide() : _login("guest"), _user_level(Beginner), _times_logged(1),
_guesses(0), _correct_guesses(0)
{
	static int id = 0;
	char buffer[16];
	_itoa_s(id++, buffer, 10);
	
	//针对guest，加入一个独一无二的活动期识别码
	_login += buffer;
}
inline bool UserProvide::operator==(const UserProvide &rhs)
{
	if (_login == rhs._login && _user_name == rhs._user_name)
	{
		return true;
	}
	return false;
}

inline bool UserProvide::operator!=(const UserProvide &rhs)
{
	return *this != rhs;
}
inline string UserProvide::level() const
{
	static string _level_table[] = {"Beginner", "Intermediate", "Advanced", "Guru"};
	return _level_table[_user_level];
}

ostream& operator<<(ostream &os, const UserProvide &rhs)
{
	os << rhs.login() << ' '
		<< rhs.level() << ' '
		<< rhs.login_count() << ' '
		<< rhs.guess_count() << ' '
		<< rhs.guess_correct() << ' '
		<< rhs.guess_average() << endl;
	return os;
}

map<string, UserProvide::ulevel> UserProvide::_level_map;

void UserProvide::init_level_map()
{
	_level_map["Beginner"] = Beginner;
	_level_map["Intermediate"] = Intermediate;
	_level_map["Advanced"] = Advanced;
	_level_map["Guru"] = Guru;
}

inline void UserProvide::reset_level(const string &level)
{
	map<string, ulevel>::iterator it;
	if (_level_map.empty())
	{
		init_level_map();
	}
	_user_level = ((it = _level_map.find(level)) != _level_map.end())
		? it->second : Beginner;
}
istream& operator>>(istream &is, UserProvide &rhs)
{
	string login, level;
	is >> login >> level;
	int lcount, gcount, gcorrect;
	is >> lcount >> gcount >> gcorrect;
	rhs.reset_login(login);
	rhs.reset_level(level);

	rhs.reset_login_count(lcount);
	rhs.reset_guess_count(gcount);
	rhs.bump_guess_correct(gcorrect);

	return is;
}
 
int main()
{
	UserProvide anon;
	cout << anon;
	UserProvide anon_too;
	cout << anon_too;

	UserProvide anna("AnnaL", UserProvide::Guru);
	cout << anna;
	anna.bump_guess_count(27);
	anna.bump_guess_correct(25);
	anna.bump_login_count();
	cout << anna;
	cin >> anon;
	cout << anon;
}
*/
//练习4.5
/*
typedef float elemtype;
class Matrix
{
public:
	Matrix()
	{
		for (int i = 0; i < 4; i++)
		{
			vector<elemtype> tmp;
			for (int j = 0; j < 4; j++)
			{
				_matrix[i][j] = 0.;
			}
		}
	}

	Matrix(const elemtype a[])
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				_matrix[i][j] = a[i * 4 + j];
			}
		}
	}
	ostream& print_Matrix( ostream & os) const
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				os << _matrix[i][j] << "  ";
			}
			os << endl;
		}
		return os;
	}
	friend Matrix operator+(const Matrix &, const Matrix &);
	friend Matrix operator*(const Matrix &, const Matrix &);
	void operator+=(const Matrix &ms);

private:
	elemtype _matrix[4][4];
};
inline ostream &operator<<(ostream& os, const Matrix &m)
{
	return m.print_Matrix(os);
}
Matrix operator+(const Matrix &re, const Matrix &ms) 
{
	Matrix result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result._matrix[i][j] = re._matrix[i][j] + ms._matrix[i][j];
		}
	}
	return result;
}
Matrix operator*(const Matrix &re, const Matrix &ms) 
{
	Matrix result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result._matrix[i][j] = re._matrix[i][0] * ms._matrix[0][j] + re._matrix[i][1] * ms._matrix[1][j] 
				+ re._matrix[i][2] * ms._matrix[2][j] + re._matrix[i][3] * ms._matrix[3][j];
		}
	}
	return result;
}
void Matrix::operator+=(const Matrix &ms)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->_matrix[i][j] = this->_matrix[i][j] + ms._matrix[i][j];
		}
	}
}

int main()
{
	Matrix m;
	//m.print_Matrix();
	cout << m;
	cout << endl;
	elemtype ar[16] = {1., 0., 0., 0., 0., 1., 0., 0.,
	0., 0., 1., 0., 0., 0., 0., 1.};
	Matrix id( ar );
	//id.print_Matrix();
	cout << id;
	cout << endl;
	Matrix m2( id );
	m = id;
	//m2.print_Matrix();
	cout << m2;
	cout << endl;
	//m.print_Matrix();
	cout << m;
	cout << endl;
	elemtype ar2[16] = {
		1.3, 0.4, 2.6, 8.2, 6.2, 1.7, 1.3, 8.3,
		4.2, 7.4, 2.7, 1.9, 6.3, 8.1, 5.6, 6.6 };
	Matrix m3( ar2 );
	//m3.print_Matrix();
	cout << m3;
	cout << endl;
	Matrix m4 = m3 * id;
	//m4.print_Matrix();
	cout << m4;
	cout << endl;
	Matrix m5 = m3 + m4;
	//m5.print_Matrix();
	cout << m5;
	cout << endl;
	m3 += m4;
	//m3.print_Matrix();
	cout << m3;
	cout << endl;
	return 0;
}
*/