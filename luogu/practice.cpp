
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int vis[1100][1100],i,j,k,l,m,n,len,lem,num;
char s[1100],c[1100],sh[1100];
void dfs(int i,int j,int k)
{
	if(sh[k]=='\0')
	{
		num=1;
		return ;
	}
	if(num)
	return ;
	if(vis[i][j])
	return ;
	if(sh[k]!=s[i]&&sh[k]!=c[j])//匹配不住直接结束 
	return ;
	if(sh[k]==s[i]&&i<len)//如果跟第一个匹配住了 ，标记这点用过了 
	{
		vis[i][j]=1;
		dfs(i+1,j,k+1);//搜索下一个点 
	}
	if(sh[k]==c[j]&&j<lem)//如果跟第二个匹配住了，标记这点用过了 
	{
		vis[i][j]=1;
		dfs(i,j+1,k+1);//搜索下一个点 
	}
}
int main()
{
	scanf("%d",&k);
	int cnt=1;
	while(k--)
	{
		scanf("%s%s%s",s,c,sh);
		memset(vis,0,sizeof(vis)); 
		len=strlen(s);
		lem=strlen(c);
		l=strlen(sh);
		if(l!=len+lem)
		{
			printf("Data set %d: no\n",cnt++);
			continue;	
		}
		num=0;
		dfs(0,0,0);
		if(num)
		printf("Data set %d: yes\n",cnt++);
		else
		printf("Data set %d: no\n",cnt++);
	}
}
