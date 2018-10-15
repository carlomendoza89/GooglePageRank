#include <iostream>
#include "page_rank.hpp"
#include "connectivity_matrix.hpp"
#include "matrix.hpp"
#include <string>

using namespace std;

int main() {
    std::string name = "connectivity.txt";

    page_rank *pr = new page_rank(name);
    pr->set_importance();
    pr->make_stochastic();
    pr->set_Q();
    pr->set_transition_matrix();
    pr->set_rank();
    pr->markov();
    pr->final();
    pr->print();

    return 0;
}