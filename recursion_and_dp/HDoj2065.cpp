/*红色病毒——递推*/
#include <iostream>

using namespace std;

int main()
{
    int n,i;
    long long m;
    int s[] = {4, 8,16,32,64,28,56,12,24,48,
    96,92,84,68,36,72,44,88,76,52};//f=2^(n-1)+4^(n-1)=2^(n-1)+2^(2*n-2),所以这里先列出了2的次方的循环
    while (cin >> n && n)          
    {                             
        for(i = 1; i <= n; i++)
        {
            cin >> m;
            cout << "Case " << i << ": ";
            if(m == 1)
            {
                cout << "2" << endl;
            }
            else if(m == 2)
            {
                cout << "6" << endl;
            }
            else
            {
                cout << (s[(m-3)%20]+s[(2*m-4)%20])%100 << endl;//对于输入m来说，先要(m-1)和(2*m-2)，再用（结果-2）% 20，
            }                                                   //如果两个s加超过100还要%100取最后两位
        }
        cout << endl;
    }
    return 0;
}