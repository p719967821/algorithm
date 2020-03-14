/**快速排序**/
#include <iostream>
#define N 10000

using namespace std;

int a[N];
int n;

void quicksort(int left, int right);

int main()
{
    int i;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quicksort(0,n-1);
    for(i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}

void quicksort(int left, int right)
{
    int i,j,t;
    i = left;
    j = right + 1;
    if(left < right)
    {
        while (1)
        {
            while(i < n - 1 && a[++i] < a[left]);
            while (j > -1 && a[--j] > a[left]);
            if(i >= j)break;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        t = a[left];
        a[left] = a[j];
        a[j] = t;
        quicksort(left,j-1);
        quicksort(j+1,right);
    }
}