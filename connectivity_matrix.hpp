//
// Created by Carlo on 2018-10-13.
//

#pragma once

#include "matrix.hpp"

class connectivity_matrix : public matrix
{
public:
//     Default constructor which initializes a square 1 x 1 connectivity matrix that contains a 0.0
    connectivity_matrix();

//     Constructor that accepts a positive integer n and creates a
//     square n x n connectivity matrix that contains 0.0s
//
//     Throws an exception if either integer passed to the constructor is zero or negative
    connectivity_matrix(int n);

//     Constructor that accepts two positive integers r and c and
//     creates a connectivity matrix with r rows and c columns that contains 0.0s
//
//     Throws an exception if either integer passed to the constructor is zero or negative
    connectivity_matrix(int r, int c);

//     Constructor that accepts an array of double.
//     The size of the array must have an integer square root.
//     Creates a square connectivity matrix of that size and populates it using the values from the array.
//
//     Throw an exception if the size of the array does not have an integer square root
    connectivity_matrix(double array[], int size);

//     Destructor
    ~connectivity_matrix() override;

//     Connectivity matrix mutator that accepts two integers representing row and column and a double
//     representing the new value for the specified location
//
//     Throws an exception if the integers are negative or too large
    void set_value(int r, int c, double val) override;

    double get_out_degree(int col);
};
