// Tala Sadat Yasanpoor 610392156
#include <iostream>
#include <string>
using namespace std ;

int main ()
{
	string str , sub ;
	int count = 0 , i = 0 , a = 0 ;
	cin >> str >> sub ;
	for ( int j = 0 ; j < str.size() ; ++j )
	{
		if ( str[j] == sub[i])
		{
			++i ;
			count = 1 ;
		}
		else 
		{
			count = 0 ;
			j = j-i ;
			i = 0 ;
		}
		if ( count == 1 && i == sub.size() )
		{
			a++ ;
		}
		if ( i == sub.size() )
		{
			i = 0 ;
			j = j-sub.size()+1 ;
		}
	}
	cout << a << "\n" ;
	return 0 ;
}
