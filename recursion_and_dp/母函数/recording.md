<font color='red' size='5'>母函数定义</font>：[here](https://www.cnblogs.com/Enumz/p/3878652.html)（已经解释的很清楚了，但是其中有一个写错了，问题分析2中： **其中(1+X^2 +X^4 +X^6 +...)可以看做{不使用1毛的邮票，使用1个1毛的邮票，使用2个1毛的邮票...}** 这句话错误，应该是不使用2毛的邮票，使用1个2毛的邮票，使用2个2毛的邮票...）
***

**1028.cpp**
    1.具体内容见母函数定义和HDoj1028.cpp中的注解
**1171.cpp**
    1.这个题就是把一些数尽量分平均。一般做这种题就是用的完全背包，其实也是可以用母函数做的，方法就是，先把这些数的总价值求出来，然后套母函数的公式，求解出n=最大值时的情况，其实也就求出了1到最大值之间的所有值的是否能成的情况，因为要求输出的两个数，前比后大，所以从最大值/2向一开始找，如果其c1[i] != 0，则输出该值即可，另一个就是 最大值-该值。另外要注意的就是，直接找其中的一个值即可，另一个直接用减法，不用想着两个值可能用到同一个数的情况，因为要知道，所有的数之和一定，当确定其中一个值能成后，在所有的数中间刨去组成该值的数，剩下的自然就可以直接组成另一个数。
背包问题：https://www.cnblogs.com/daoluanxiaozi/archive/2012/05/06/2486105.html