//
// Created by Carlo on 2018-10-08.
//

#include "matrix.hpp"
#include <array>
#include <ctgmath>

using namespace std;

matrix::matrix() : rows{1}, cols{1}, default_value{0.0}, data(cols, vector<double>(rows, default_value))
{
    cout << "matrix default constructor called" << endl;
}

matrix::matrix(int n) : rows {n}, cols{n}, default_value{0.0}
{
    cout << "matrix square constructor called" << endl;

    if(n <= 0)
    {
        throw "Matrix size too small.  Choose a number greater than 0";
    }
    else
    {
        for(int i=0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++) {
                data[i].push_back(default_value);
            }
        }
    }
}

matrix::matrix(int r, int c) : rows{r}, cols{c}, default_value{0.0}
{
    cout << "matrix row and column constructor called" << endl;

    if(r <= 0)
    {
        throw "Row size too small.  Choose a number greater than 0";
    }
    else if(c <= 0)
    {
        throw "Column size too small.  Choose a number greater than 0";
    }
    else
    {
        for(int i=0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++) {
                data[i].push_back(default_value);
            }
        }
    }
}

matrix::matrix(double *array)
{
    cout << "matrix array constructor called" << endl;

    int size = sizeof(array)/sizeof(*array);

    if(sqrt(size) - floor(sqrt(size)) != 0)
    {
        throw "Size of array must have an integer square root";
    }
    else
    {
        rows, cols = size;
        int counter = 0;
        for(int i=0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++) {
                data[i].push_back(array[counter]);
                counter++;
            }
        }
    }
}

void matrix::set_value(int r, int c, double val)
{
    data[r][c] = val;
}

double matrix::get_value(int r, int c)
{
    return data[r][c];
}

void matrix::clear()
{
    for(int i=0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++) {
            data[i].push_back(default_value);
        }
    }
}

ostream& matrix::output(ostream &os) const
{
    for(auto vec : data)
    {
        for(auto val : vec)
        {
            os << val;
        }
        os << endl;
    }
}

ostream& operator<<(ostream& os, const matrix& m) {
    return m.output(os);
}