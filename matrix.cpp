//
// Created by Carlo on 2018-10-08.
//

#include "matrix.hpp"
#include <array>
#include <ctgmath>

using namespace std;

matrix::matrix() : rows{1}, cols{1}, default_value{0.0}, data(rows, vector<double>(cols, default_value))
{
    cout << "matrix default constructor called" << endl;
}

matrix::matrix(int n) : rows {n}, cols{n}, default_value{0.0}, data(rows, vector<double>(cols, default_value))
{
    cout << "matrix square constructor called" << endl;
    if(n <= 0)
    {
        throw "Matrix size too small. Choose a number greater than 0";
    }
}

matrix::matrix(int r, int c) : rows{r}, cols{c}, default_value{0.0}, data(rows, vector<double>(cols, default_value))
{
    cout << "matrix row and column constructor called" << endl;

    if(r <= 0)
    {
        throw "Row size too small. Choose a number greater than 0";
    }
    else if(c <= 0)
    {
        throw "Column size too small. Choose a number greater than 0";
    }
}

matrix::matrix(double* array, int size): rows{1}, cols{1}, default_value{0.0}, data(rows, vector<double>(cols, default_value))
{
    cout << "matrix array constructor called" << endl;

    int root = sqrt(size);

    if(root - floor(sqrt(size)) != 0)
    {
        throw "Size of array must have an integer square root";
    }
    else
    {
        rows = root;
        cols = root;

        data.resize(root);
        for(int row = 0; row < root; row++)
        {
            data.at(row).resize(root);
        }

        int counter = 0;
        for(int i=0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++) {
                set_value(i, j, array[counter]);
                counter++;
            }
        }
    }
}

void matrix::set_value(int r, int c, double val)
{
    data.at(r).at(c) = val;
}

double matrix::get_value(int r, int c)
{
    return data.at(r).at(c);
}

matrix::~matrix()
{
    cout << "Matrix destructor called" << endl;
}

void matrix::clear()
{
    for(int i=0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++) {
            set_value(i, j, default_value);
        }
    }
}

ostream& matrix::output(ostream &os) const
{
    for(vector<vector<double>>::size_type i = 0; i < data.size(); i++)
    {
        for(vector<double>::size_type j = 0; j < data[i].size(); j++)
        {
            os << data.at(i).at(j) << " ";
        }
        os << endl;
    }
    os << endl;
}

ostream& operator<<(ostream& os, const matrix& m) {
    return m.output(os);
}

bool operator==(const matrix &lhs, const matrix &rhs)
{
    if(lhs.rows == rhs.rows && lhs.cols == rhs.rows)
    {
        for(int i = 0; i < lhs.rows; ++i)
        {
            for(int j = 0; j < lhs.cols; ++j) {
                if (lhs.data[i][j] != rhs.data[i][j])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool operator!=(const matrix &lhs, const matrix &rhs)
{
    return !operator==(lhs, rhs);
}

matrix& matrix::operator++()
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            set_value(i, j, get_value(i, j) + 1.0);
        }
    }
    return *this;
}

matrix matrix::operator++(int)
{
    matrix tmp(*this);
    operator++();
    return tmp;
}

matrix& matrix::operator--()
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            set_value(i, j, get_value(i, j) - 1.0);
        }
    }
    return *this;
}

matrix matrix::operator--(int)
{
    matrix tmp(*this);
    operator--();
    return tmp;
}

void swap(matrix& first, matrix& second)
{
    using std::swap;
    swap(first.rows, second.rows);
    swap(first.cols, second.cols);
    swap(first.data, second.data);
}

matrix& matrix::operator=(matrix other)
{
    swap(*this, other);
    return *this;
}

matrix& matrix::operator+=(const matrix &rhs)
{
    if(rows != rhs.rows || cols != rhs.cols)
    {
        throw "can only add matrices of same size";
    }
    else
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                data[i][j] += rhs.data[i][j];
            }
        }
    }
    return *this;
}

matrix& matrix::operator-=(const matrix &rhs)
{
    if(rows != rhs.rows || cols != rhs.cols)
    {
        throw "can only subtract matrices of same size";
    }
    else
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                data[i][j] -= rhs.data[i][j];
            }
        }
    }
    return *this;
}

matrix operator+(matrix lhs, const matrix rhs)
{
    if(lhs.rows != rhs.rows || lhs.cols != rhs.cols)
    {
        throw "can only add matrices of same size";
    }
    else
    {
        lhs += rhs;
    }
    return lhs;
}

matrix operator-(matrix lhs, const matrix rhs)
{
    if(lhs.rows != rhs.rows || lhs.cols != rhs.cols)
    {
        throw "can only subtract matrices of same size";
    }
    else
    {
        lhs -= rhs;
    }
    return lhs;
}

matrix& matrix::operator*=(const matrix &rhs)
{
    if(cols != rhs.rows)
    {
        throw "number of columns is not equal to number of rows of second matrix";
    }
    else
    {
        matrix *tmp = new matrix(rows, rhs.cols);
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < rhs.cols; ++j)
            {
                for(int k = 0; k < cols; ++k)
                {
                    tmp->data[i][j] += data[i][k] * rhs.data[k][j];
                }
            }
        }
        *this = *tmp;
    }
    return *this;
}

matrix operator*(matrix lhs, const matrix rhs)
{
    if(lhs.cols != rhs.rows)
    {
        throw "number of columns of first matrix is not equal to number of rows of second matrix";
    }
    else
    {
        lhs *= rhs;
    }
    return lhs;
}