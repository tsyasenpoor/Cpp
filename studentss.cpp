#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;

class Date {
     
     public:
       Date( int = 1, int = 1, int = 1900 );
       void print() const;
       ~Date();
    private:
       int month;
       int day;
       int year;
       int checkDay( int ) const;  
}; 

Date::Date( int mn, int dy, int yr )
{
    if ( mn > 0 && mn <= 12 )
        month = mn;
    else
	{
        month = 1;
        cout << "Month " << mn << " invalid. Set to month 1.\n";
    }
    year = yr;
    day = checkDay( dy );
    cout << "Date object constructor for date ";                
    print();                                                    
    cout << endl;                                               
}

int Date::checkDay( int testDay ) const
{
    static const int daysPerMonth[ 13 ] ={ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
    	return testDay;
    if ( month == 2 && testDay == 29 &&( year % 400 == 0 ||( year % 4 == 0 && year % 100 != 0 ) ) )
        return testDay;
    cout << "Day " << testDay << " invalid. Set to day 1.\n";
    return 1;
}

void Date::print() const
{
    cout << month << '/' << day << '/' << year; 
}     

Date::~Date()                                              
{                                                          
    cout << "Date object destructor for date ";             
    print();                                                
	cout << endl;                                                                                                      
}

class Students {
    
    public:
       Students(const char *, const char *,int, const char *, const Date &, const char *, double);
       void print() const;
       ~Students();  
    private:
       char firstName[ 25 ];
       char lastName[ 25 ];
       int ID;
       char Gender[2];
       const Date birthDate;
       char City[25];
       double GPA;
}; 

Students::Students( const char *first, const char *last, int id , const char* g , const Date &dateOfBirth, const char* city,double gpa): birthDate( dateOfBirth )       
{
	int length = strlen( first );
    length = ( length < 25 ? length : 24 );
    strncpy( firstName, first, length );
    firstName[ length ] = '\0';
    length = strlen( last );
    length = ( length < 25 ? length : 24 );
    strncpy( lastName, last, length );
    lastName[ length ] = '\0';
    length = strlen( g );
    length = ( length < 25 ? length : 24 );
    strncpy( Gender, g, length );
    Gender[ length ] = '\0';
    length = strlen( city );
    length = ( length < 25 ? length : 24 );
    strncpy( City, city, length );
    City[ length ] = '\0';
    ID=id ;
    GPA=gpa;
    cout << "Students object constructor: "<< firstName << ' ' << lastName << ' '<< ID << ' ' << Gender << ' '<< City<< endl;   
}

void Students::print() const
{
    cout << lastName << ", " << firstName << "," << ID <<","<<Gender<<","<<City<<","<<GPA<<endl;
    cout << "  Birth date: ";
    birthDate.print();
    cout << endl;
}
    
Students::~Students()                                          
{                                                              
    cout << "Students object destructor: "<< lastName << ", " << firstName << endl;             
}                                  

/*class vorudi 
{
	public:
		int Average ();
		int MaxGrade ();
		int SortLastName ();
		int SortGrade ();
	
	private:
		Students S[20] ;
		double sum , average ;
		
		
};

int GeneralMathematics :: Average ()
{
	for (int i=0 ; i<20 ; i++)
	{
		sum+= S[i].GPA;
	}
	average=sum/20 ;
	cout << average << endl  ;
	return 0 ;
}

int GeneralMathematics :: MaxGrade ()
{
	int temp=0 , max=0 ;
	for (int i=0 ; i<20 ; i++)
	{
		if(S[i].GPA>temp)
		{
			temp=S[i].GPA ;
			max=i ;
		}
	}
	cout << " The Maximum Grade is : " << S[max].name << " "<< S[max].lastName << " " << temp << endl ;
	return 0 ;
}

int GeneralMathematics :: SortLastName ()
{
	string swap[20];
	for (int i=0 ; i<20 ; i++)
	{
		for (int j=i+1 ; j<20 ;j++)
			if (S[i]lastName > S[j].lastName)
			{
				swap[i] = S[i].lastName ;
				S[i].lastName = S[j].lastName ;
				S[j].lastName = swap[i] ;
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
}*/

int main()
{
    Date birth( 7, 24, 1949 );                                             
    Students first( "Bob", "Jones",123456,"M", birth ,"NewYork",2.5);
    cout << '\n';
    first.print();
    cout << "\nTest Date constructor with invalid values:\n";
    Date lastDayOff( 14, 35, 1994 ); 
    cout << endl;
    return 0;    
}

