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
#include "huffman.h"

using namespace std;

#define MAX_N 128

//Constructor :
Tree::Tree()
{
	for (int i=0 ; i<MAX_N; i++)
		freq[i] = 0 ;
	for (int j=0 ; j<2*MAX_N ; j++)
		parent[j]= -1 ;
}

//A function that codes the text and prints each characters code in the file !
string Tree::MakeTree()
{
	string result ;
	ifstream fin ("hfmn.txt") ;
	fin >> noskipws ;
	char c ;
	while (fin >> c)
	{
		if ( c == '\n' )
			continue;
		freq[c]++ ;
	}
	n = 0 ;
	for (int i =0 ; i<MAX_N ; i++)
	{
		if (freq[i]>0)
		{
			UsedChar.push_back(i) ;
			PQ.push(make_pair(-freq[i],n)) ; //Put the mines , becouse the priority queue works with the maximum number , but we need minimum!
			n++ ;
		}
	}
	while (PQ.size() > 1)
	{
		pair<int,int> min1 = PQ.top() ; //Finds the minimum amount!
		PQ.pop() ; //Deletes the minimum amount , to find the minimum among other amounts !
		pair<int, int> min2 = PQ.top() ;
		PQ.pop() ;
		parent[min1.second]=n ;
		parent[min2.second]=n ;
		dir[min1.second]='0' ;
		dir[min2.second]='1' ;
		pair<int,int> temp ;
		temp.first = min1.first+min2.first ;
		temp.second = n ;
		PQ.push(temp);
		n++ ;
	}
	for (int j=0 ; j<UsedChar.size() ; j++)
	{
		int c = UsedChar[j];
		int k=j ;
		while(parent[k]!=-1)
		{
			code[c]=dir[k]+code[c] ;
			k=parent[k] ;
		}
		result+=char(c) ;
		result+=""+code[c]+"\n";
	}
	ofstream res ;
	res.open("tree.txt");
	res<<result ;
	res.close() ;
	fin.close();
	return result ;
}

void Tree::encode()
{
	ifstream fin ("hfmn.txt") ;
	fin >> noskipws ;
	char c ;
	ofstream code_res ("code.txt" , ios::binary ) ;
	while (fin >> c)
	{
		if ( c == '\n' )
			continue;
		code_res << code[c] ;
	}
	code_res.close() ;
	fin.close() ;	
}

int main ()
{
	Tree t ;
	t.MakeTree() ;
	t.encode() ;
	return 0;
}
