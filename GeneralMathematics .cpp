//Tala Sadat Yasanpoor 610392156
#include<bits/stdc++.h>

using namespace std;

class GeneralMathematics
{
	string Name[20] , LastName[20] ;
	double MidTerm[20] , Final[20] , Ex[20] , FinalGrade[20] , dif[20] , power[20] ;
	int sum , sumpow ;
	double average , variance ;
	public :

	//Member Functions Decleration 
	int Input ();
	int CalcFinalGrade ();
	int Print ();
	int Average ();
	int Variance ();
	int MaxGrade ();
	int SortLastName ();
	int SortGrade ();
	int Lower2Upper ();

};

//Member Functions Definitions 
int GeneralMathematics :: Input ()
{
	for (int i=0 ; i<20 ; i++)
	{
	cout << " Enter Students name , last name , midterm score , final score and exercise score : " << i+1 << " : "  << endl ;
	cin >> Name[i] >> LastName[i] >> MidTerm[i] >> Final[i] >> Ex[i]  ;
	if ( (MidTerm[i]>60) || (MidTerm[i]<0))
		cout << "MidTerm score must be between 0 and 60 " << endl ;
	if ( (Final[i]>80) || (Final[i]<0))
		cout << "Final score must be between 0 and 80 " << endl ;
	if ( (Ex[i]>60) || (Ex[i]<0))
		cout << "Exercise score must be between 0 and 60 " << endl ;
	}
	return 0 ;
}

int GeneralMathematics :: CalcFinalGrade ()
{
	for (int i=0 ; i<20 ; i++)
	{
		FinalGrade[i] = (MidTerm[i]+Final[i]+Ex[i])/10;
	}
	cout << FinalGrade << endl ;
	return 0 ;
}

int GeneralMathematics :: Print () 
{
	for (int i=0 ; i<2 ; i++)
	{
		cout << Name[i] << " " << LastName[i] << " " << FinalGrade[i] << endl;
	}
	return 0;
}

int GeneralMathematics :: Average ()
{
	for (int i=0 ; i<20 ; i++)
	{
		sum+= FinalGrade[i];
	}
	average=sum/20 ;
	cout << average << endl  ;
	return 0 ;
}

int GeneralMathematics :: Variance ()
{
	for (int i=0 ; i<20 ; i++)
	{
		dif[i] = FinalGrade[i]-average ;
		power[i] = (dif[i])*(dif[i]) ;
		sumpow+=power[i] ;
	}
	variance = sumpow/20 ;
	cout << variance << endl ;
	return 0 ;
}

int GeneralMathematics :: MaxGrade ()
{
	int temp=0 , max=0 ;
	for (int i=0 ; i<20 ; i++)
	{
		if(FinalGrade[i]>temp)
		{
			temp=FinalGrade[i] ;
			max=i ;
		}
	}
	cout << " The Maximum Grade is : " << Name[max] << " "<< LastName[max] << " " << temp << endl ;
	return 0 ;
}

int GeneralMathematics :: SortLastName ()
{
	string swap[20];
	for (int i=0 ; i<20 ; i++)
	{
		for (int j=i+1 ; j<20 ;j++)
			if (LastName[i] > LastName[j])
			{
				swap[i] = LastName[i] ;
				LastName[i] = LastName[j] ;
				LastName[j] = swap[i] ;
			}
	}
	cout << swap << endl ;
	return 0 ;
}

int GeneralMathematics :: SortGrade () 
{
	double swap2[20] ;
	string swap3[20] ;
	for (int i=0 ; i<19; i++)
	{
		for (int j=i+1 ; j<20 ; j++)
		{
			if (FinalGrade[i]>FinalGrade[j])
			{
				swap2[i]=FinalGrade[i];
				FinalGrade[i]=FinalGrade[j] ;
				FinalGrade[j]=swap2[i] ;
				swap3[i]=LastName[i] ;
				LastName[i]=LastName[j] ;
				LastName[j]=swap3[i];
			}
		}
	}
	return 0 ;
}

int GeneralMathematics :: Lower2Upper ()
{
	string name="", lastname, name1, lastname1;
    for(int i=0 ; i<20 ; i++)
	{
      name = Name[i] ;
      lastname = LastName[i] ;
      name1="";
      lastname1="";
      for(int j=0 ; j<name.size() ; j++)
	  {
	  if( (int)( name[j] ) > 96)
	  name1= name1+ (char)((int)name[j]-32);
	  else
	  name1= name1 + name[j];
      }
      Name[i] = name1 ;
	  for(int j=0 ; j<lastname.size() ; j++)
	  {
	  if((int)lastname[j]>96)
	  lastname1= lastname1+ (char)((int)lastname[j]-32);
	  else
	  lastname1= lastname1 + lastname[j];
      }
      LastName[i] = lastname1;
    } 
	return 0 ;   
  }   

int main()
{
	GeneralMathematics GM ;
	GM.Input ();
	GM.CalcFinalGrade();
	GM.Print();
	GM.Average();
	GM.Variance();
	GM.MaxGrade();
	GM.SortLastName();
	GM.Print();
	GM.SortGrade();
	GM.Print();
	GM.Lower2Upper();
	
	return 0 ;
}
