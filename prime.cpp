//Tala Sadat Yasanpoor 610392156
#include <iostream>
using namespace std;
 int main()
 { 	
	int num,count=0;
	cout<<"ENTER NUMBER: "; 	
	cin>>num; 	
	for(int i=1;i<=num;i++) 	
	 { 		
		if (num%i==0) 	
	   {
	    	count++;
	   }	 	
	 }
	if(count==2)
   { 
		cout<<"Yes"; 	
   } 	
	else 	
   { 	
		cout<<"NO"; 	
   } 	
return 0; 
} 
