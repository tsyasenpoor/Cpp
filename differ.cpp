#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std ;

int stringtoint (string a)
{
  int l, sum = 0 , sign = 1 ;
  if( a[0] == '-' )
  {
    a=a.substr(1,a.size()-1);
    sign=-1;
  }
  for(int j=1; j<=a.size(); j++)
  {
    l = (int) a[a.size()-j] - '0';
    sum = sum + l* (int) pow (10,j-1);
  }
  sum=sum*sign;
  return sum;
}

string inttostring (int m)
{
	int i = 0 , sign = 1 ;
  	if( m < 0 )
	{
    sign = -1 ;
    m = m*sign ;
    }
  
  string t = "" ;
  if( m == 0 )
    t.insert(0,1,'0'+0);
  else {
    while( m != 0 )
	{
      i = m % 10 ;
      t.insert( 0 , 1 , '0' + i ) ;
      m = m / 10 ;
    }
  }
    if( sign == -1 )
      t='-'+t;
  return t;
}

string differential (string S)
{
 string co , po , s , s1 = "" , q , h ;
  
  int k = 0 , coe = 1 , pow = 0 , j = 0 , power = 0 , coef = 1 ;

  for(int i = 0 ; i <= S.size() ; i++)
  {  
    if ( S[i] == 'x' )
	{
      if ( i == k ) 
      {
      	coe = 1 ;
	  }
      else
	  {
		co = S.substr(k , i-k ) ;
		coe = stringtoint(co) ;
      }
      if(i != S.size()-1)
	  {
		if( S[i+1] == '^')
		{
	  	j = i+2 ;
	  	while ( j != S.size() && S[j] != '+')
		{
	    	j++;
	  	}
        po = S.substr ( i+2 , j-i-2 ) ;
	    pow = stringtoint (po) ;
	    i = j-1 ;
	    k = j ;
		}
		else if ( S[i+1] == '+')
		{
		  pow = 1 ;
    	  k = i+2 ;
	      i = i+1 ;
		}
      }
      else
      {
      	pow = 1 ;
	  }
    power = pow-1 ;
    coef = coe*pow ;
    q = inttostring (coef) ;
    h = inttostring (power) ;
      s1 = '('+ q +','+ h +')'+',';
      s = s + s1 ;
    }
  }  
  return s ;
}

int main()
{
 string s ;
  cin >> s;
  int k=0,j=0;
    
  string dif , diff="";
  int size=s.size();
  for(int i=0 ; i<s.size(); i++)
  {
    if(s[i]=='+')
	{
      dif=s.substr(k,i-k);
      size=size-i;
      k=i+1;
  diff=diff + differential(dif);
    }
  }
  int a=0;
  if(k<s.size()){
    dif=s.substr(k,s.size()-k);
    for(int r=0; r < dif.size();r++)
	{
      if(dif[r]=='x')
	a=1;
    }
    if(a==1){
      diff=diff+ differential(dif);
      diff=diff.substr(0,diff.size()-1);
    }
    else
      diff= diff + '(' +'0'+','+'-'+'1'+')';
  }
  
  cout<< diff << "\n" ;
  return 0;
}
