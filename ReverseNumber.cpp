//Tala Sadat Yasanpoor 610392156
#include <iostream>
using namespace std ;

int main()
{
	int n , rev=0  ;
	cout << "enter a positive number : " ;
	cin >> n ;
	bool val=false;
	if(n<0)
	{
		val=true;
		n*=-1;
	}
	while (n > 0)
	{
		rev*=10;
		rev+=n%10 ;
		n=n/10 ;
	}
	cout << "reversed number is : " << rev ;
	if(val)
		cout<<-1*rev;
	else
		cout<<rev;
	return 0 ;
}
