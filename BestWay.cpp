//Tala Sadat Yasanpoor 610392156
#include <iostream>
using namespace std ;

int main()
{
    int m,n; 
    cin >> m >> n ; 
    int mat[m][n];

    for ( int i = 0 ; i < m ; i++ )
    {
    	for ( int j = 0 ; j < n ; j++)
    	{
    		cin >> mat[i][j] ;
		}
	}

    int BestWay[m][n]; 

    BestWay[0][0] = mat[0][0];

	for ( int j = 1 ; j < n ; j++ )
	{
        BestWay[0][j] = BestWay[0][j-1] + mat[0][j];
	}
	
	for ( int i = 1 ; i < m ; i++ )
	{
        BestWay[i][0] = BestWay[i-1][0] + mat[i][0];
    }

	for ( int i = 1 ; i < m ; i++)
    {
        for ( int j = 1 ; j < n ; j++)
        {
            BestWay[i][j] = min(BestWay[i-1][j],BestWay[i][j-1]) + mat[i][j];
        }
    }

    cout<< BestWay[m-1][n-1];
    return 0;
}
