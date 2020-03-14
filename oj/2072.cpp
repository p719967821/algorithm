#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    int i,len,letter[30],x,sum;
    string s;
    while (1)
    {
        memset(letter,0,sizeof(letter));
        getline(cin,s);
        sum = 0;
        if(s == "#")
        {
            break;
        }
        len = s.length();
        for(i = 0; i < len; i++)
        {
            if(s[i] != ' ')
            {
                x = s[i] - 'a' + 1;
                if(letter[x] == 0)
                {
                    letter[x] = 1;
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}