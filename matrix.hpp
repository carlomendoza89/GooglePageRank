//
// Created by Carlo on 2018-10-08.
//

#pragma once
#include<iostream>
#include <vector>

constexpr double default_value = 0.0;

class matrix
{
protected:
    int rows, cols;
    std::vector<std::vector<double>> data;
public:
//     Default constructor which initializes a square 1 x 1 matrix that contains a 0.0
    matrix();

//     Constructor that accepts a positive integer n and creates a
//     square n x n matrix that contains 0.0s
//
//     Throws an exception if either integer passed to the constructor is zero or negative

    matrix(int n);

//     Constructor that accepts two positive integers r and c and
//     creates a matrix with r rows and c columns that contains 0.0s
//
//     Throws an exception if either integer passed to the constructor is zero or negative
     matrix(int r, int c);

//     Constructor that accepts an array of double.
//     The size of the array must have an integer square root.
//     Creates a square matrix of that size and populates it using the values from the array.
//
//     Throw an exception if the size of the array does not have an integer square root
     matrix(double array[], int size);

//     Matrix mutator that accepts two integers representing row and column and a double
//     representing the new value for the specified location
//
//     Throws an exception if the integers are negative or too large
     virtual void set_value(int r, int c, double val);

//     Matrix accessor that accepts two integers representing row and column and
//     returns the value in the matrix from the specified location
     double get_value(int r, int c);

//     Sets all values in the matrix to 0.0
     void clear();

//     Destructor
     virtual ~matrix();

//     Prepares output to send to an output stream
     std::ostream& output(std::ostream& os) const;

//     Insertion operator to print matrix
     friend std::ostream& operator<<(std::ostream& os, const matrix& m);

//     Check if the matrices are the same size and contain the same values in the same locations.
     friend bool operator==(const matrix &lhs, const matrix &rhs);

//     If the matrices are not the same size, and they do not contain the same values, they are not equal
     friend bool operator!=(const matrix &lhs, const matrix &rhs);

//     Unary prefix increment. Increments each value in the matrix by 1.0
     matrix& operator++();

//     Unary postfix increment. Increments each value in the matrix by 1.0
     matrix operator++(int);

//     Unary prefix decrement. Decrements each value in the matrix by 1.0
    matrix& operator--();

//     Unary postfix decrement. Decrements each value in the matrix by 1.0
//     @return the matrix with decremented values
    matrix operator--(int);


//     Swaps matrix attributes with another matrix
    friend void swap(matrix& first, matrix& second);

//     Assignment operator to apply swap
    matrix& operator=(matrix other);

//     Adds data values from another matrix
    matrix& operator+=(const matrix &rhs);

//     Subtracts data values from another matrix
    matrix& operator-=(const matrix &rhs);

//     Adds data values of one matrix to another
    friend matrix operator+(matrix lhs, const matrix rhs);


//     Subtracts data values of one matrix from another
    friend matrix operator-(matrix lhs, const matrix rhs);

//     Multiplies data by values from another matrix
    matrix& operator*=(const matrix &rhs);

//     Mutliplies data values of one matrix by another
    friend matrix operator*(matrix lhs, const matrix rhs);
};
