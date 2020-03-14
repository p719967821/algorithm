#include <iostream>
#define INF 100000

using namespace std;

int a[81][81];

int main()
{
    int i,j,left,right,two = 1;
    int row,col,sum = 0,allsum = 0;
    cin >> row >> col;
    for(i = 1; i <= row; i++)
    {
        for(j = 1; j <= col; j++)
        {
            cin >> a[i][j];
        }   
    }
    for(i = 1; i <= col; i++)
    {
        for(j = 1; j <= row; j++)
        {
            left = 1;
            right = col;    
            while(a[j][left] == INF && left <= col)
            {
                left++;
            }
            while(a[j][right] == INF && right > 0)
            {
                right--;
            }
            if(a[j][left] >= a[j][right])
            {
                sum += a[j][right];
                a[j][right] = INF;
            }
            else
            {
                sum += a[j][left];
                a[j][left] = INF;
            }
        }
        two *= 2;
        allsum += sum * two; 
        sum = 0;
    }
    cout << allsum << endl;
    return 0;
}                                                                                                                        
        
