//
// Created by Carlo on 2018-10-11.
//

//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
//#include "matrix.hpp"
//
//double mat[4] = {11.1, 22.2, 33.3, 44.4};
//
//matrix *a = new matrix();
//matrix *b = new matrix(3);
//matrix *c = new matrix(2, 4);
//matrix *d = new matrix(mat, 4);
//matrix *e(d);
//
//TEST_CASE("Matrix constructors work", "[matrix]")
//{
//    REQUIRE(a->get_value(0, 0) == 0.0);
//    REQUIRE(b->get_value(2, 2) == 0.0);
//    REQUIRE(c->get_value(1, 3) == 0.0);
//    REQUIRE(d->get_value(1, 1) == 44.4);
//}
//
//TEST_CASE("Basic matrix functions work", "[matrix]")
//{
//    a->set_value(0,0, 55.5);
//
//    REQUIRE(a->get_value(0, 0) == 55.5);
//
//    a->clear();
//
//    REQUIRE(a->get_value(0, 0) == 0.0);
//}
//
//TEST_CASE("Equality operators can compare matrices," "[matrix]")
//{
//    REQUIRE(e == d);
//    REQUIRE(a != b);
//}
//
//TEST_CASE("Matrices can be incremented", "[matrix]")
//{
//    *b++;
//    REQUIRE(b->get_value(2, 2) == 1.0);
//    ++(*c);
//    REQUIRE(c->get_value(1 ,3) == 1.0);
//}

////TEST MAIN FUNCTIONS
//    double mat[4] = {11.1, 22.2, 33.3, 44.4};
//
////    matrix *x = new matrix(-1, 13);
////
////    cout << *x;
//
//    matrix *a = new matrix();
//    matrix *b = new matrix(3);
//    matrix *c = new matrix(2, 4);
//    matrix *d = new matrix(mat, 4);
//    matrix *e(d);
//
//    b->set_value(1, 1, 11.1);
//
//    b->clear();
//
//    cout << *a;
//    cout << *b;
//    cout << *c;
//    cout << *d;
//
//    if(a != b)
//    {
//        cout << "no match =)" << "\n" << endl;
//    } else
//    {
//        cout << "match =(" << "\n" << endl;
//    }
//
//    if(e == d)
//    {
//        cout << "match =)" << "\n" << endl;
//    } else {
//        cout << "no match =(" << "\n" << endl;
//    }
//
//    cout << "test ++matrix" << endl;
//    ++(*b);
//    cout << *b;
//
//    cout << "test matrix++" << endl;
//    (*c)++;
//    cout << *c;
//
//    cout << "test --matrix" << endl;
//    --(*b);
//    cout << *b;
//
//    cout << "test matrix--" << endl;
//    (*c)--;
//    cout << *c;
//
//    cout << "test = operator" << endl;
//    *a = *e;
//
//    cout << *a;
//    cout << *e;
//
//    cout << "test += operator" << endl;
//    *a += *e;
//
//    cout << *a;
//    cout << *e;
//
//    cout << "test -= operator" << endl;
//    *a -= *e;
//
//    cout << *a;
//    cout << *e;
//
//    cout << "test + operator" << endl;
//    cout << *a + *e;
//    cout << "test - operator" << endl;
//    cout << *a - *e;
//
//    double mat_1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    double mat_2[6] = {1, 2, 3, 4, 5, 6};
//
//    matrix *f = new matrix(mat_1, 9);
//    matrix *g = new matrix(3, 2);
//
//    int counter = 0;
//    for(int i = 0; i < 3; i++)
//    {
//        for(int j = 0; j < 2; j++)
//        {
//            g->set_value(i, j, mat_2[counter]);
//            counter++;
//        }
//    }
//
//    cout << "created 2 new test matrices" << endl;
//    cout << *f;
//    cout << *g;
//
//    cout << "test *= operator" << endl;
//    *f *= *g;
//
//    cout << *f;
//    cout << *g;
//
//    cout << "test * operator" << endl;
//    cout << *f * *d;
//
//    double mat_3[4] = {1, 0, 1, 0};
//
//    connectivity_matrix *h = new connectivity_matrix;
//    connectivity_matrix *i = new connectivity_matrix(4);
//    connectivity_matrix *j = new connectivity_matrix(4, 6);
//    connectivity_matrix *k = new connectivity_matrix(mat_3, 4);
//
//    cout << *h;
//    cout << *i;
//    cout << *j;
//    cout << *k;
//
//    h->set_value(0, 0, 1);
//
//    cout << h->get_value(0, 0);