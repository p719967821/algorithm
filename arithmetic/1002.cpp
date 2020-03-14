/**归并排序**/
#include <iostream>
#define N 10001

using namespace std;

int n;
int a[N];
int tmp[N];

void mergesort(int left, int right);

int main()
{
    int i;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergesort(0,n-1);
    for(i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}

void mergesort(int left, int right)
{
    int mid;
    mid = (left + right) / 2;
    if(left == right)
    {
        return;
    }
    else
    {
        mergesort(left,mid);
        mergesort(mid+1,right);
        int i,j,k;
        for(i = left,j = mid+1,k=left;i <= mid && j<=right;)
        {
            if(a[i] < a[j])
            {
                tmp[k++] = a[i++];
            }
            else
            {
                tmp[k++] = a[j++];
            }
        }
        while (i <= mid)
        {
            tmp[k++] = a[i++];
        }
        while (j <= right)
        {
            tmp[k++] = a[j++];
        }
        for(k = left; k <= right; k++)
        {
            a[k] = tmp[k];
        }
    }
    
}