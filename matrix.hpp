//
// Created by Carlo on 2018-10-08.
//

#pragma once
#include<iostream>
#include <vector>

class matrix
{
private:
    int rows, cols;
    double default_value;
//    double *data;
    std::vector<std::vector<double>> data;
public:
    /**
     * Default constructor which initializes a square 1 x 1 matrix that contains a 0.0
     */
    matrix();

    /**
     * Constructor that accepts a positive integer n and creates a
     * square n x n matrix that contains 0.0s
     *
     * Throws an exception if either integer passed to the constructor is zero or negative
     *
     * @param n number of rows and columns for square matrix
     */
    matrix(int n);

    /**
     * Constructor that accepts two positive integers r and c and
     * creates a matrix with r rows and c columns that contains 0.0s
     *
     * Throws an exception if either integer passed to the constructor is zero or negative
     *
     * @param r number of rows
     * @param c number of columns
     */
     matrix(int r, int c);

     /**
      * Constructor that accepts an array of double.
      * The size of the array must have an integer square root.
      * Creates a square matrix of that size and populates it using the values from the array.
      *
      * Throw an exception if the size of the array does not have an integer square root
      *
      * @param array the array of values to populate matrix
      * @param size the size of the array
      */
     matrix(double *array, int size);

     /**
      * Matrix mutator that accepts two integers representing row and column and a double
      * representing the new value for the specified location
      *
      * Throws an exception if the integers are negative or too large
      *
      * @param r selected row
      * @param c selected column
      * @param val new value to set
      */
     void set_value(int r, int c, double val);

     /**
      * Matrix accessor that accepts two integers representing row and column and
      * returns the value in the matrix from the specified location
      *
      * @param r selected row
      * @param c selected column
      * @return value from matrix
      */
     double get_value(int r, int c);

     /**
      * sets all values in the matrix to 0.0
      */
     void clear();

     /**
      * Destructor
      */
     ~matrix();

     /**
      * Prepares output to send to an output stream
      *
      * @param os output stream to send properties to
      * @return os
      */
     std::ostream& output(std::ostream& os) const;

     /**
      * Insertion operator to print matrix
      *
      * @param os output stream to print to
      * @param m matrix to send
      * @return output to print
      */
     friend std::ostream& operator<<(std::ostream& os, const matrix& m);

     /**
      * check if the matrices are the same size and contain the same values in the same locations.
      *
      * @param lhs first matrix to check
      * @param rhs second matrix to check
      * @return whether lhs and rhs are equal
      */
     friend bool operator==(const matrix &lhs, const matrix &rhs);

     /**
      * If the matrices are not the same size, and they do not contain the same values, they are not equal
      *
      * @param lhs first matrix to check
      * @param rhs second matrix to check
      * @return whether lhs and rhs are not equal
      */
     friend bool operator!=(const matrix &lhs, const matrix &rhs);

     /**
      * Unary prefix increment. Increments each value in the matrix by 1.0
      * @return the matrix with incremented values
      */
     matrix& operator++();

     /**
      * Unary postfix increment. Increments each value in the matrix by 1.0
      * @return the matrix with incremented values
      */
     matrix operator++(int);

    /**
     * Unary prefix decrement. Decrements each value in the matrix by 1.0
     * @return the matrix with decremented values
     */
    matrix& operator--();

    /**
     * Unary postfix decrement. Decrements each value in the matrix by 1.0
     * @return the matrix with decremented values
     */
    matrix operator--(int);

    /**
     * Swaps matrix attributes with another matrix
     *
     * @param first matrix to swap
     * @param second matrix to be swapped with
     */
    friend void swap(matrix& first, matrix& second);

    /**
     * Assignment operator to apply swap
     *
     * @param other matrix to swap with
     * @return newly swapped matrix
     */
    matrix& operator=(matrix other);

    /**
     * Adds data values from another matrix
     *
     * @param rhs matrix to be added
     * @return matrix with new data values
     */
    matrix& operator+=(const matrix &rhs);

    /**
     * Subtracts data values from another matrix
     *
     * @param rhs matrix to be subtracted
     * @return matrix with new data values
     */
    matrix& operator-=(const matrix &rhs);

    /**
     * Adds data values of one matrix to another
     *
     * @param lhs first matrix
     * @param rhs matrix to add
     * @return lhs with new values
     */
    friend matrix operator+(matrix lhs, const matrix rhs);

    /**
     * Subtracts data values of one matrix from another
     *
     * @param lhs first matrix
     * @param rhs matrix to subtract
     * @return lhs with new values
     */
    friend matrix operator-(matrix lhs, const matrix rhs);
};
