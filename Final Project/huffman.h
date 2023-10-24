#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <complex>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 128

class Tree
{
	public :
		Tree();
		void readfile ();
		string MakeTree ();
		void encode ();
	
	private :
		int freq[MAX_N];
		int parent[2*MAX_N] ;
		char dir[2*MAX_N];
		vector <char> UsedChar ;
		priority_queue <pair<int,int> > PQ ;
		int n ;
		string code[MAX_N] ;
};

#endif
