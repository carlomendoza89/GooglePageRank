//
// Created by Carlo on 2018-10-13.
//

#include "connectivity_matrix.hpp"
#include <ctgmath>
#include <stdexcept>

using namespace std;

connectivity_matrix::connectivity_matrix() : matrix()
{
//    cout << "connectivity matrix default constructor called" << endl;
}

connectivity_matrix::connectivity_matrix(int n) : matrix(n)
{
//    cout << "connectivity matrix square constructor called" << endl;
}

connectivity_matrix::connectivity_matrix(int r, int c) : matrix(r, c)
{
//    cout << "connectivity matrix row and column constructor called" << endl;

    if(r <= 0)
    {
        throw std::invalid_argument("Row size too small. Choose a number greater than 0");
    }
    else if(c <= 0)
    {
        throw std::invalid_argument("Column size too small. Choose a number greater than 0");
    }
    data.resize(r);
    for(int row = 0; row < r; row++)
    {
        data.at(row).resize(c);
    }
}

connectivity_matrix::connectivity_matrix(double array[], int size) : matrix(array, size)
{
//    cout << "connectivity matrix array constructor called" << endl;

    double root = sqrt(size);

    if(root - floor(sqrt(size)) != 0)
    {
        throw std::invalid_argument("Size of array must have an integer square root");
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
                if(array[counter] != 0 && array[counter] != 1)
                {
                    throw std::invalid_argument("Connectivity matrix can only contain 1s and 0s");
                }
                else
                {
                    set_value(i, j, array[counter]);
                    counter++;
                }
            }
        }
    }
}

void connectivity_matrix::set_value(int r, int c, double val)
{
    if(val != 0 && val != 1)
    {
        throw std::invalid_argument("Connectivity matrix can only contain 1s and 0s");
    }
    else if(r < 0 || r > rows)
    {
        throw std::invalid_argument("Row does not exist");
    }
    else if(c < 0 || c > cols)
    {
        throw std::invalid_argument("Column does not exist");
    }
    else
    {
        data[r][c] = val;
    }
}

connectivity_matrix::~connectivity_matrix()
{
//    cout << "Connectivity matrix destructor called" << endl;
}

double connectivity_matrix::get_out_degree(int col)
{
    double out_degree = 0;
    for(int i = 0; i < rows; i++)
    {
        out_degree += get_value(i, col);
    }

    return out_degree;
}