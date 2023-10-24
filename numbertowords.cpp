//Tala sadat yasanpoor 610392156
#include <iostream>
#include <string>
using namespace std ;
int main () 
{
	string num ;
	cin >> num ;
	string onesName[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" } ;
    string teensName[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" } ;
    string tensName[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" } ;
    string illionPreName[] = { "m", "b", "tr", "quadr", "quint", "sext", "sept", "oct", "non", "dec" } ;
    string decillionPreName[]={ "un", "duo", "tre", "quattuor", "quin", "sex", "septen", "octo", "novem" } ;
    string vegintillionPreName[] ={ "" , "un", "duo", "tre", "quattuor", "quin", "sex", "septen", "octo", "novem" } ;
    if ( num[0] == '0')
     cout << "zero" ;
	while ( num.size()%3 != 0 )
	{
		num = '0' + num ;
	}
	for ( int i = 0 ; i < num.size() ; i+=3 )
	{
		if ( num [i] == '0' && num [i+1] == '0' && num [i+2] == '0' )
			continue ;	
		if ( num[i + 0] > '0' )
			cout << onesName[ num[i + 0] - '0' - 1 ] << " hundred ";
		if( num[i + 1] == '0' || num[i + 1] > '1' )
        {
            if( num[i + 1] > '1' ) cout << tensName[ num[i + 1] - '0' - 2 ] << " ";
            if( num[i + 2] > '0' ) cout << onesName[ num[i + 2] - '0' - 1 ] << " ";
        }
        else
            cout << teensName[ num[i + 2] - '0' ] << " ";   
        int j = ( num.size() - i )/3;
        if( j == 2 ) 
			cout << "thousand ";
        else if( j > 2 )
        {
            if( j <= 12 ) 
				cout << illionPreName[ j - 3 ];
            else if( j <= 21 ) 
				cout << decillionPreName[ j - 13 ] << "dec";
            else if( j <= 30 ) 
				cout << vegintillionPreName[ j - 22 ] << "vigint";
            cout << "illion ";
        }
	}
	return 0 ;
}
