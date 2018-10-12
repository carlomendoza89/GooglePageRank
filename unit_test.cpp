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