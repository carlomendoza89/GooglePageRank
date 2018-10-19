//
// Created by Carlo on 2018-10-14.
//

#pragma once

#include "connectivity_matrix.hpp"
#include <iostream>
#include <fstream>
#include "string"

constexpr double p = 0.85;

class page_rank
{
private:
    int n;
    std::vector<double> web;
    connectivity_matrix g;
    matrix S;
    matrix Q;
    matrix M;
    matrix rank;
public:
//    Constructor for page_rank, creates connectivity matrix and calls functions needed to convert to ranking
    page_rank(std::string &file_name);

//    Sets initial importance matrix of links for each page
    void set_importance();

//    Ensures all columns of matrix sum to 1
    void make_stochastic();

//    Creates Q matrix for calculating transition matrix
    void set_Q();

//    Creates a matrix using connectivity matrix to show probabilities
    void set_transition_matrix();

//    Creates ranking matrix
    void set_rank();

//    Multiplies transition matrix by rank matrix until rank stops changing
    void markov();

//    Divide each element in rank by sum of values in rank
    void final();

//    Prints out final ranking determined by connectivity matrix
    void print();
};