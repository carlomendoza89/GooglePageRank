#include <iostream>
#include "page_rank.hpp"
#include "connectivity_matrix.hpp"
#include "matrix.hpp"
#include <string>

using namespace std;

int main() {
    try {
        std::string name = "connectivity.txt";

        page_rank *pr = new page_rank(name);
        pr->print();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what();
    }

    return 0;
}