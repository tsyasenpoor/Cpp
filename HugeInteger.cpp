#include <iostream>
#include <string>
#include <cmath>
using namespace std ;

class HugeInteger {
	private:
		int HugeInt[40] ;
		int key ;
		
	public:
		HugeInteger(void); //constructor
		HugeInteger (int);
  		HugeInteger (string);
  		HugeInteger (const HugeInteger &);
    	~HugeInteger(void); //destructor
    	friend ostream &operator << (ostream & , HugeInteger &) ;
    	friend istream &operator >> (istream & , HugeInteger &) ;
    	const HugeInteger &operator + (const HugeInteger &) ;
    	const HugeInteger &operator - (const HugeInteger &) ;
    	const HugeInteger &operator * (const HugeInteger &) ;
    	const HugeInteger &operator = (const HugeInteger &) ;
    	HugeInteger &operator++(); //preincrement operator
		HugeInteger operator++(int); //postincrement operator
		HugeInteger &operator--(); //predencrement operator
		HugeInteger operator--( int ); //postdecrement operator
		int SetKey (int) ;
		int GetKey () ;
		const HugeInteger encrypt (const HugeInteger & );
		const HugeInteger decrypt (const HugeInteger & );
};

//constructor : 
HugeInteger :: HugeInteger(void)
{
	for (int i = 39; i >= 0; i--)
        this ->HugeInt[i] = 0;
}

//copy constructors :
HugeInteger::HugeInteger(int integer)
{
  for(int i=0 ; i<40 ; i++){
    (*this).HugeInt[39-i] = integer % ((int) pow (10,i));
    integer/=10;
  }
}

HugeInteger::HugeInteger (string str){
  int L = str.length();
  for(int i=0; i<L ; i++)
    (*this).HugeInt[39 - i] = (int) str[L - i] - '0'; 
  for(int i=0 ; i<40 - L ; i++)
    (*this).HugeInt[i]=0;
}

HugeInteger::HugeInteger(const HugeInteger & number){
  for(int i=0 ; i<40 ; i++)
    (*this).HugeInt[i]=number.HugeInt[i];
}

//destructor :
HugeInteger::~HugeInteger() 
{
    //de-allocates internal array
}

ostream &operator << (ostream &output , HugeInteger &number )
{
	for (int i = 0 ; i<40 ; i++)
	{
		output << number.HugeInt[i] ;	
	}
	return output ;
}

istream &operator >> (istream &input , HugeInteger &number )
{
	for (int i = 0 ; i<40 ; i++)
	{
		input >> number.HugeInt[i] ;	
	}
	return input ;
}

const HugeInteger &HugeInteger :: operator + (const HugeInteger &number )
{
	HugeInteger result ;
    for (int i = 0; i < 40; i++)
    {
        result.HugeInt[i] = this -> HugeInt[i] + number.HugeInt[i] ;
    }
    return result ;
}

const HugeInteger &HugeInteger :: operator - (const HugeInteger &number )
{
	HugeInteger result ;
    for (int i = 0; i < 40; i++)
    {
        result.HugeInt[i] = this->HugeInt[i] - number.HugeInt[i] ;
    }
    return result ;
}

const HugeInteger &HugeInteger :: operator * (const HugeInteger &number )
{
	HugeInteger result ;
    for (int i = 0; i < 40 ; i++)
    {
        result.HugeInt[i] = this->HugeInt[i] * number.HugeInt[i] ;
    }
    return result ;
}

const HugeInteger &HugeInteger :: operator = (const HugeInteger &number )
{
	HugeInteger result ;
	for (int i = 0 ; i < 40 ; i++)
	{
		result.HugeInt[i]=number.HugeInt[i] ;
	}
	return result ;
}

HugeInteger &HugeInteger :: operator++()
{
  return *this;
}

HugeInteger HugeInteger :: operator++(int num)
{
  HugeInteger temp1(*this);
  operator++();
  return temp1; 
}

HugeInteger &HugeInteger :: operator--()
{
  return *this;
}

HugeInteger HugeInteger :: operator--(int)
{
  HugeInteger temp2(*this);
  operator--();
  return temp2; 
}

int HugeInteger :: SetKey (int num) 
{
	key=num ;		
	return 0 ;
}

int HugeInteger :: GetKey () 
{
	return key;
}

const HugeInteger HugeInteger :: encrypt (const HugeInteger &number)
{
	HugeInteger result;
  	for(int j=0; j<key ; j++)
    	result.HugeInt[j]=number.HugeInt[40 -key + j];
 	for(int i=0; i<(40-key);i++)
      result.HugeInt[i+key]=number.HugeInt[i];
  	for(int i=0 ; i<40 ; i++)
    	result.HugeInt[i]=number.HugeInt[i];
    return result ;
}

const HugeInteger HugeInteger :: decrypt (const HugeInteger &number)
{
  HugeInteger result;
  for(int i=0 ; i<key ; i++)
    result.HugeInt[40-key + i]=number.HugeInt[i];
  for(int j=0; j<40-key ; j++)
    result.HugeInt[j]=number.HugeInt[j+key];
  for(int i=0 ; i<40 ; i++)
    result.HugeInt[i]=number.HugeInt[i] ;
  return result;
}

int main()
{
	HugeInteger myHugeInteger ;	
	return 0 ;
}
