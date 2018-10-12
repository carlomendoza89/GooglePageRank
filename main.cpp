#include <iostream>
#include "matrix.hpp"

using namespace std;

int main() {

    double mat[4] = {11.1, 22.2, 33.3, 44.4};

    matrix *mat_a = new matrix();
    matrix *mat_b = new matrix(3);
    matrix *mat_c = new matrix(2, 4);
    matrix *mat_d = new matrix(mat, 4);
    matrix *mat_e(mat_d);

    mat_b->set_value(1, 1, 11.1);

    mat_b->clear();

    double val = mat_d->get_value(1, 1);

    cout << val;

    cout << *mat_a;
    cout << *mat_b;
    cout << *mat_c;
    cout << *mat_d;

    if(mat_a != mat_b)
    {
        cout << "no match =)"<<endl;
    } else {
        cout << "match =("<<endl;
    }

    if(mat_e == mat_d)
    {
        cout << "match =)"<<endl;
    } else {
        cout << "no match =("<<endl;
    }

//    *mat_b++;
//    cout << *mat_b;
//
//    ++(*mat_c);
//    cout << *mat_c;



    return 0;
}