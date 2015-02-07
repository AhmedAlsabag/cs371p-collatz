// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// -----------
// TestCollatz
// -----------

// ----
// read
// ----

TEST(Collatz, read) {
    string s("1 10\n");
    const pair<int, int> p = collatz_read(s);
    ASSERT_EQ( 1, p.first);
    ASSERT_EQ(10, p.second);}

TEST(Collatz, readA) {
    string s("250 2\n");
    const pair<int, int> p = collatz_read(s);
    ASSERT_EQ( 250, p.first);
    ASSERT_EQ(2, p.second);}

TEST(Collatz, readB) {
    string s("13 10\n");
    const pair<int, int> p = collatz_read(s);
    ASSERT_EQ( 13, p.first);
    ASSERT_EQ(10, p.second);}

TEST(Collatz, readC) {
    string s("21 220\n");
    const pair<int, int> p = collatz_read(s);
    ASSERT_EQ( 21, p.first);
    ASSERT_EQ(220, p.second);}
// ----
// eval
// ----

TEST(Collatz, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(Collatz, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(Collatz, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(Collatz, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

TEST(Collatz, eval_5) {
    const int v = collatz_eval(10, 1);
    ASSERT_EQ(20, v);}

TEST(Collatz, eval_6) {
    const int v = collatz_eval(32, 50);
    ASSERT_EQ(110, v);}

TEST(Collatz, eval_7) {
    const int v = collatz_eval(500000, 500002);
    ASSERT_EQ(152, v);}
// -----
// print
// -----

TEST(Collatz, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(Collatz, printA) {
    ostringstream w;
    collatz_print(w, 10, 1, 20);
    ASSERT_EQ("10 1 20\n", w.str());}

TEST(Collatz, printB) {
    ostringstream w;
    collatz_print(w, 32, 50, 110);
    ASSERT_EQ("32 50 110\n", w.str());}

TEST(Collatz, printC) {
    ostringstream w;
    collatz_print(w, 500000, 500002, 152);
    ASSERT_EQ("500000 500002 152\n", w.str());}
// -----
// solve
// -----

TEST(Collatz, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(Collatz, solveA) {
    istringstream r("23 24\n24 23\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("23 24 16\n24 23 16\n", w.str());}

TEST(Collatz, solveB) {
    istringstream r("1 45\n45 1\n145 145\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 45 112\n45 1 112\n145 145 117\n", w.str());}

TEST(Collatz, solveC) {
    istringstream r("1 145\n146 144\n12 1234\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 145 122\n146 144 117\n12 1234 182\n", w.str());}
/*
% ls -al /usr/include/gtest/
...
gtest.h
...



% locate libgtest.a
/usr/lib/libgtest.a
...



% locate libpthread.a
...
/usr/lib32/libpthread.a



% locate libgtest_main.a
/usr/lib/libgtest_main.a
...



% g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lgtest -lgtest_main -lpthread



% valgrind TestCollatz        >  TestCollatz.out 2>&1
% gcov-4.7 -b Collatz.c++     >> TestCollatz.out
% gcov-4.7 -b TestCollatz.c++ >> TestCollatz.out



% cat TestCollatz.out
==14225== Memcheck, a memory error detector
==14225== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==14225== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==14225== Command: TestCollatz
==14225==
Running main() from gtest_main.cc
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from Collatz
[ RUN      ] Collatz.read
[       OK ] Collatz.read (31 ms)
[ RUN      ] Collatz.eval_1
[       OK ] Collatz.eval_1 (5 ms)
[ RUN      ] Collatz.eval_2
[       OK ] Collatz.eval_2 (3 ms)
[ RUN      ] Collatz.eval_3
[       OK ] Collatz.eval_3 (3 ms)
[ RUN      ] Collatz.eval_4
[       OK ] Collatz.eval_4 (3 ms)
[ RUN      ] Collatz.print
[       OK ] Collatz.print (17 ms)
[ RUN      ] Collatz.solve
[       OK ] Collatz.solve (10 ms)
[----------] 7 tests from Collatz (88 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (132 ms total)
[  PASSED  ] 7 tests.
==14225==
==14225== HEAP SUMMARY:
==14225==     in use at exit: 0 bytes in 0 blocks
==14225==   total heap usage: 495 allocs, 495 frees, 70,302 bytes allocated
==14225==
==14225== All heap blocks were freed -- no leaks are possible
==14225==
==14225== For counts of detected and suppressed errors, rerun with: -v
==14225== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
File 'Collatz.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'Collatz.c++.gcov'
...
File 'TestCollatz.c++'
Lines executed:100.00% of 26
Branches executed:57.14% of 224
Taken at least once:28.57% of 224
Calls executed:54.07% of 209
Creating 'TestCollatz.c++.gcov'
...
*/
