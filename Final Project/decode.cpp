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
#include "decode.h"

using namespace std ;

//Constructor :
Decode::Decode ()
{
	ifstream coded ("tree.txt") ; //Reads the huffman code !
	coded >> noskipws;
	char c ;
	while (coded >> c)
	{
		if ( c == '\n' )
			continue;
		string str ;
		coded >> str ;
		emb[str]=c ;
	}
	ifstream BinText ("code.txt") ; //Binary code file !
	ofstream Out("decoded.txt") ; //Makes a new file to print the decoded text in !
	string whole ;
	BinText >> whole ;
	while (whole.size()>0)
	{
		int count = 1 ;
		string sub = whole.substr(0,1) ;
		while (emb.find(sub)==emb.end())
		{
			count++ ;
			sub = whole.substr(0,count) ;
		}
		Out << emb[sub] ;
		whole = whole.substr(count );
	}
}

int main()
{
	Decode d ;
	return 0;
}
