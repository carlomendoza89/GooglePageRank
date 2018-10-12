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

    cout << "test ++matrix" << endl;
    ++(*b);
    cout << *b;

    cout << "test matrix++" << endl;
    (*c)++;
    cout << *c;

    cout << "test --matrix" << endl;
    --(*b);
    cout << *b;

    cout << "test matrix--" << endl;
    (*c)--;
    cout << *c;

    cout << "test = operator" << endl;
    *a = *e;

    cout << *a;
    cout << *e;

    cout << "test += operator" << endl;
    *a += *e;

    cout << *a;
    cout << *e;

    cout << "test -= operator" << endl;
    *a -= *e;

    cout << *a;
    cout << *e;

    cout << "test + operator" << endl;
    cout << *a + *e;
    cout << "test - operator" << endl;
    cout << *a - *e;

    double mat_1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double mat_2[6] = {1, 2, 3, 4, 5, 6};

    matrix *f = new matrix(mat_1, 9);
    matrix *g = new matrix(3, 2);

    int counter = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            g->set_value(i, j, mat_2[counter]);
            counter++;
        }
    }

    cout << "created 2 new test matrices" << endl;
    cout << *f;
    cout << *g;

    cout << "test *= operator" << endl;
    *f *= *g;

    cout << *f;
    cout << *g;

    cout << "test * operator" << endl;
    cout << *f * *d;


    return 0;
}