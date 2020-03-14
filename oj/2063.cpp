/*过山车*/
/*匈牙利算法*/
#include <iostream>
#include <string.h>

using namespace std;

int n,mn,wn;
int map[505][505],vis[505],match[505];//分别代表1）可能匹配的情况2）对于每一个女生，男生是否匹配过，所以在对新的女生讨论时先要
                                      //清空3）match[j]=i代表j男生已经和i女生匹配，注意要反着用
bool find(int i);

int main()
{
    int i,a,b,sum = 0;
    while (cin >> n && n)
    {
    cin >> mn >> wn;
    for(i = 0; i < n; i++)
    {
        cin >> a >> b;
        map[a][b] = 1;
    }
    for(i = 1; i <= mn; i++)
    {
        memset(vis,0,sizeof(vis));
        if(find(i))
        {
            sum++;
        }
    }
    cout << sum << endl;
    sum = 0;
    memset(map,0,sizeof(map));
    memset(match,0,sizeof(match));
    }
    return 0;
}

bool find(int i)
{
    int j;
    for(j = 1; j <= mn; j++)//历遍每个男生
    {
        if(map[i][j] == 1 && vis[j] == 0)//有线且该女生没有访问过该男生
        {
            vis[j] = 1;
            if(match[j] == 0 || find(match[j]))//前一部分代表该男生还没有被匹配，所以两者可以匹配，后部分是代表
            {                                  //寻找该男生原本匹配的女生能否再找一个其他男生匹配，因为该女生已经占了该男生的名额，即vis【】=1
                match[j] = i;                  //所以find该男生原本匹配的女生时，不会再寻找该男生，而是看其他男生是否可以，从而达到目的，如果能找到，则
                return true;                   //match在过程中就可以改变，且返回true。
            }
        }
    }
    return false;
}