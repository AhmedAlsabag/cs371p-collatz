// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"

using namespace std;
int cache [1000000];
// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    // <your code>
	if ((i==1 && j==0) ||( i==0 && j==1)){
    		return 2;
    	}
	int previous=0;	
	int current=0;
	if (i>j){
	int temp=i;
	i=j;
	j=temp;
	}
	int halfVal=(j/2)+1;
	if (i<halfVal){
	i=halfVal;

	}
	for (int q=i; q<j; q++){
		int a= q;
		while (a!=1){
			if (a<1000000){
	                       	 if(cache[a]!=0){
        	              	  current+=cache[a];
                       		 break;
                       		 }
			}
			if (a%2==0){
			a=a/2;
			}else {
			a=(3*a)+1;
			}
		current++;
		}
	
	if (cache[q]==0){
	cache[q]=current;
	}
	if (current>previous){
	previous=current;
	}
	current=0;

	}
	 if (i==j){
        	 while (i!=1){
                        if (i%2==0){
                        i=i/2;
                        }else {
                        i=(3*i)+1;
                        }
               	  current++;
                }	
        return current;
    	
    }
    return previous+1;}

//return 1;}
// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
