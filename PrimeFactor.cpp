//Tala Sadat Yasanpoor 610392156
#include <iostream>
using namespace std ;

int main()
{
	int num ;
	cout << "enter a number : " ;
	cin >> num ;
	for (int j=1 ; j<=num ; ++j)
	{
		int count=0 ;
		for (int i=1 ; i<=j ; ++i)
		{
			if(j%i==0)
			count++ ;
		}
		if (count==2)
		{
			if (num%j==0)
			cout << j << "\n" ;
		}		
	}
	return 0 ;
}
