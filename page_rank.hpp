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
    matrix s;
    matrix Q;
    matrix transition_matrix;
    matrix rank;
public:
    page_rank();
    page_rank(std::string &file_name);
    connectivity_matrix get_web();
    void set_importance();
    matrix get_importance();
    void make_stochastic();
    void set_Q();
    matrix get_Q();
    void set_transition_matrix();
    matrix get_transition_matrix();
    void set_rank();
    matrix get_rank();
    void markov();
    void final();
    void print();
};