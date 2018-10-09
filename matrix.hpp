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
      */
     matrix(double array[]);

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
};
