/**二分查找**/

#include <iostream>
#define N 50001//注意后台的测例很多，一定要给够空间

using namespace std;

int n,m,k;
int a[N],b[N];

void binarysearch(int x, int left, int right);

int main()
{
    int i,x;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    } 
    cin >> m;
    for(i = 0; i < m; i++)
    {
       cin >> x;
       binarysearch(x,0,n-1); 
       k++;
    }
    for(i = 0; i < m; i++)
    {
        if(b[i] == 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    } 
    return 0;
}
 
void binarysearch(int x, int left, int right)
{
    int mid;
    while(left <= right)
    {
       mid = (left + right) / 2;
       if(a[mid] == x)
       {
           b[k] = 1;
           break;
       }
       else if(a[mid] > x)
       {
           right = mid - 1; 
       }
       else
       {
           left = mid + 1;
       }
    }
}