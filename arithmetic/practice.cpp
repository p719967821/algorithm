#include <iostream>
 
using namespace std;
 
int n;
int a[10000];
int tmp[10000];
 
void mergesort(int a[],int st, int ed);
 
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
 
    mergesort(a,0,n-1);
 
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
 
void mergesort(int a[],int st, int ed)
{
    if(st==ed)
        return;
    else
    {
        int mid=(st+ed)/2;
        mergesort(a,st,mid);
        mergesort(a,mid+1,ed);
 
        int i,j,k;
        for(i=st,j=mid+1,k=st; i<=mid&&j<=ed; )
        {
            if(a[i]>a[j])
            {
                tmp[k++]=a[j++];
            }
            else
            {
                tmp[k++]=a[i++];
            }
        }
        while(i<=mid)
        {
            tmp[k++]=a[i++];
        }
        while(j<=ed)
        {
            tmp[k++]=a[j++];
        }
        for(k=st; k<=ed; k++)
        {
            a[k]=tmp[k];
        }
    }
}
