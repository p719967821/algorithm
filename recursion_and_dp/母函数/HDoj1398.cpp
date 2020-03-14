#include <iostream>

using namespace std;

int v[]={1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289};

int main()
{
    int n,i,j,k;
    int c1[310],c2[310];//c1是起始，c2是缓存
    while (cin >> n && n)
    {
        for(i = 0; i <= n; i++)
        {
            c1[i] = 1;
            c2[i] = 0;
        }
        i = 1;
        while (n >= v[i])//可能会相等的所以是>=
        {
            for(j = 0; j <= n; j++)
            {
                for(k = 0; k+j <= n; k=k+v[i])
                {
                    c2[k+j] += c1[j];
                }
            }
            for(j = 0; j <= n; j++)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
            i++;
        }
        cout << c1[n] << endl;
    }
    return 0;
}