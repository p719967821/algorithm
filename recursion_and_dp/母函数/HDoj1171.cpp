#include<cstdio> 
#include <cstring>
using namespace std;
 
int n,v[55],m[55],c1[1000005],c2[1000005];
 
int main(){
	while(~scanf("%d",&n)){
		if(n < 0)
			break;
		int sum = 0;
		for(int i = 0; i < n; i ++){
			scanf("%d%d",&v[i],&m[i]);
			sum += v[i] * m[i];
		}
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(int i = 0; i <= m[0]; i ++){//对第一个表达式进行初始化 
			c1[i * v[0]] = 1;
		}
		
		for(int i = 1; i < n; i ++){//对剩余的表达式进行计算 
			for(int j = 0; j <= sum; j ++){//选取c1[]多项式中的第j个元素 
				if(c1[j]){//幂指数为j的系数存在 
					for(int k = 0; k <= m[i] * v[i]; k += v[i]){//度第i个多项式选取元素进行计算 
						if(k + j <= sum)
							c2[k + j] += c1[j];//c2[k+j] = c2[k+j] + c1[j]*1,c2[k]的系数为1 
					}
				}
			}
			for(int j = 0; j <= sum; j ++){//更新 
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
			
		int aver = sum / 2;//判断平均值的系数是否唯一 
		for(int i = aver; i >= 0; i --){
			if(c1[i]){//找到最接近平均值的一个数 
				printf("%d %d\n",sum-i,i);
				break;
			}
		}
	}
	return 0;
}
————————————————
版权声明：本文为CSDN博主「TooSIMple_」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/i1020/article/details/70809408