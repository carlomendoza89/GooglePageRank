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
            os << data.at(i).at(j);
        }
        os << endl;
    }
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
matrix matrix::operator++(int) const
{
    matrix tmp(*this);
    operator++();
    return tmp;
}


//matrix::matrix() : rows{1}, cols{1}, default_value{0.0}, data{new double[rows*cols]}
//{
//    cout << "matrix default constructor called" << endl;
////    data = new double[rows*cols];
//}
//
//matrix::matrix(int n) : rows {n}, cols{n}, default_value{0.0}, data{new double[rows*cols]}
//{
//    cout << "matrix square constructor called" << endl;
//
//    if(n <= 0)
//    {
//        throw out_of_range("Matrix size too small.  Choose a number greater than 0");
////    } else
////    {
////        data = new double[rows*cols];
//    }
//}
//
//matrix::matrix(int r, int c) : rows{r}, cols{c}, default_value{0.0}, data{new double[rows*cols]}
//{
//    cout << "matrix row and column constructor called" << endl;
//
//    if(r <= 0)
//    {
//        throw out_of_range("Row size too small.  Choose a number greater than 0");
//    }
//    else if(c <= 0)
//    {
//        throw "Column size too small.  Choose a number greater than 0";
////    } else
////    {
////        data = new double[rows*cols];
//    }
//}
//
//matrix::matrix(double *array, int size)
//{
//    cout << "matrix array constructor called" << endl;
//
//    if(sqrt(size) - floor(sqrt(size)) != 0)
//    {
//        throw out_of_range("Size of array must have an integer square root");
//    }
//    else
//    {
//        data = array;
//    }
//}
//
//void matrix::set_value(int r, int c, double val)
//{
//    data[r * c + c] = val;
//}
//
//double matrix::get_value(int r, int c)
//{
//    return data[r * c + c];
//}
//
//matrix::~matrix()
//{
//    cout << "Matrix destructor called" << endl;
//}
//
//void matrix::clear()
//{
//    delete[] data;
//    data = new double[rows*cols];
//}
//
//ostream& matrix::output(ostream &os) const
//{
//    int count  = 0;
//    for(int i = 0; i < rows; ++i)
//    {
//        for(int j = 0; j < cols; ++j)
//        {
//            os << data[count];
//            ++count;
//        }
//        os << endl;
//    }
//}
//
//ostream& operator<<(ostream& os, const matrix& m) {
//    return m.output(os);
//}