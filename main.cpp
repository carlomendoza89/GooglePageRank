#include <iostream>
#include "matrix.hpp"

using namespace std;

int main() {
    matrix *a;
//    matrix *b;
//    matrix *c;

    a = new matrix();
//    b = new matrix(3);
//    c = new matrix(2, 4);

    cout << *a << endl;
//    cout << *b << endl;
//    cout << *c << endl;

    return 0;
}