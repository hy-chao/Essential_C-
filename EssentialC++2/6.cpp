/*
*C++Á·Ï°Ìâ£ºEssential C++ µÚÁùÕÂ
*author£ºhyc
*date£º2017.4.19
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;
//Á·Ï°6.1
/*
template <typename elemType> 
class example
{
public:
	example(elemType min, elemType max);
	example(const elemType *array, int size);
	elemType& operator[](int index);
	bool operator==(const example&)const;
	bool insert(const elemType*, int);
	bool insert(elemType);
	elemType min() const
	{
		return _min;
	}
	elemType max() const
	{
		return _max;
	}
	void min(const elemType&);
	void max(const elemType&);
	int count(const elemType &value) const;
private:
	int size;
	elemType *parray;
	elemType _min;
	elemType_max;
};
*/
//Á·Ï°6.2
/*
template <typename elemType>
class Matrix
{
	friend Matrix<elemType> operator+(const Matrix<elemType>&, const Matrix<elemType>&);
	friend Matrix<elemType> operator*(const Matrix<elemType>&, const Matrix<elemType>&);
public:
	Matrix(int rows, int columns);
	Matrix(const Matrix);
	~Matrix();
	Matrix& operator=(const Matrix&);
	void operator+=(const Matrix&);
	elemType& operator()(int row, int column)
	{
		return _matrix[row * cols() + column];
	}
	const elemType& operator()(int row, int column) const
	{
		return _matrix[row * cols() + column];
	}
	int rows() const
	{
		return _rows;
	}
	int cols() const
	{
		return _cols;
	}
	bool same_size(const Matrix& m) const
	{
		return rows() = m.rows() && cols() == m.cols();
	}
	bool comfortable(const Matrix &m) const
	{
		return cols() == m.rows();
	}
	ostream& print(ostream&) const;
protected:
	int _rows;
	int _cols;
	elemType *_matrix;
};
template <typename elemType>
inline ostream& operator<<(ostream& os, const Matrix<elemType> &m)
{
	return m.print(os);
}

template <typename elemType>
Matrix<elemType> operator+(const Matrix<elemType> &m1, const Matrix<elemType> &m2)
{
	Matrix<elemType> result(m1);
	result += m2;
	return result;
}

template <typename elemType>
Matrix<elemType> operator*(const Matrix<elemType> &m1, const Matrix<elemType> &m2)
{
	Matrix<elemType> result(m1.rows(), m2.cols());
	for (int ix = 0; ix < m1.rows(); ix++)
	{
		for (int jx = 0; jx < m1.cols(); jx++)
		{
			result(ix, jx) = 0;
		}
	}
	for (int kx = 0; kx < m1.cols(); kx++)
	{
		result(ix, jx) += m1(ix, kx) + m2(kx, jx);
	}
	return result;
}

template <typename elemType>
void Matrix<elemType>::operator+=(const Matrix &m)
{
	int matrix_size = cols() * rows();
	for (int ix = 0; ix < matrix_size(); ++ix)
	{
		(*(_matrix + ix)) += (*(m._matrix + ix));
	}
}

template <typename elemType>
void Matrix<elemType>::print(ostream &os) const
{
	int col = cols();
	int matrix_size = col * rows();
	for (int ix = 0; ix < matrix_size; ++i)
	{
		if (ix % col == 0)
			os << endl;
		os << (*(_matrix + ix)) << ' ';
	}
	os << endl;
	return os;
}
*/