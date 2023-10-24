//Tala Sadat Yasanpoor 610392156
#include <iostream>
using namespace std ;

int main()
{
	double n,m,a,b,c;
	bool val=true;
	cin>>n>>m>>a>>b>>c;
	double step=(m-n)/2, k=n+step;
	while(step>0.000001){
		double fn=a*n*n+b*n+c;
		double fm=a*m*m+b*m+c;
		double fk=a*k*k+b*k+c;
		if(fn==0){
			k=n;
			break;
		}
		if(fn*fk<0)
			m=k;
		else if(fk*fm<0)
			n=k;
		else if(fk==0)
			break;
		else if(fm==0){
			k=m;
			break;
		}
		else{
			val=false;
			break;
		}
		
		step=(m-n)/2;
		k=n+step;
		cout<<"n:  "<<n<<"   k:  "<<k<<"    m:   "<<m<<endl;
	}
	if(!val)
		cout<<"No";
	else
	cout<<n;
	return 0 ;
}
