#include <iostream>
#include "matrix.hpp"

using namespace std;

int main() {

    double mat[4] = {11.1, 22.2, 33.3, 44.4};

    matrix *a = new matrix();
    matrix *b = new matrix(3);
    matrix *c = new matrix(2, 4);
    matrix *d = new matrix(mat, 4);
    matrix *e(d);

    b->set_value(1, 1, 11.1);

    b->clear();

    cout << *a;
    cout << *b;
    cout << *c;
    cout << *d;

    if(a != b)
    {
        cout << "no match =)" << "\n" << endl;
    } else
    {
        cout << "match =(" << "\n" << endl;
    }

    if(e == d)
    {
        cout << "match =)" << "\n" << endl;
    } else {
        cout << "no match =(" << "\n" << endl;
    }

    ++(*b);
    cout << *b;

    (*c)++;
    cout << *c;

    --(*b);
    cout << *b;

    (*c)--;
    cout << *c;

    *a = *e;

    cout << *a;
    cout << *e;

    return 0;
}