//Tala Sadat Yasanpoor 610392156
#include <iostream>
#include <math.h>
using namespace std ;

int main() 
{
	int  m=0 , s=0 ,m1=0 , s1=0 , c=0 , i=1 , sum=0 , p=1 ;
	//cout << " enter two positive numbers : " << "\n" ;
	cin >> s >> m ;	
	while (m>0 || s>0)
	{
		//cout << sum << "\n" ;
		m1=m%2 ;
		s1=s%2 ;
		m/=2 ;
		s/=2 ;
		//cout << p << "\n" ;
		if ( m1+s1+c>=2 )
		{
			//cout << "b" << (m1+s1+c)*p << "\n" ;
			//sum*=10 ;
			sum+=(m1+s1+c-2)*p ;
			p*=2 ;
			c=1 ;
		}
		else
		{
			//sum*=10 ;
			//cout << "c" << c*p << "\n" ;
			sum+=(m1+s1+c)*p ;
			p*=2 ;
			c=0 ;
		}
	}
	//cout << "c" << c*p << "\n" ;
	sum+=c*p ;
	cout << sum << "\n" ;
	return 0 ;
}
