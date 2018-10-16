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
    page_rank(std::string &file_name);
    void set_importance();
    void make_stochastic();
    void set_Q();
    void set_transition_matrix();
    void set_rank();
    void markov();
    void final();
    void print();
};