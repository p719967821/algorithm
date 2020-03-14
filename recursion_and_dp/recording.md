递归与动态规划这一类题做法总结
1.对与字母数字之类的一个个增加的题，即要考虑有两个字母要过渡到三个字母的这类情况时，就只用考虑加在新加的一个总是放在队尾，在队尾分析即可，不用再考虑还要插空什么的，因为在队尾就能把所有情况都包括进去。（实验阶段，后期需看是否正确，再加以改正）

***

**2050.cpp**
    1.递推的关键是数学问题，要知道对于直线分割平面问题，第n条直线与之前的直线最多有n-1个交点，最多会新产生(n-1)+1个区域。因此折线可以类比，第n条折线与之前的折线最多有2*2(n-1)个交点，最多会新产生2 *2(n-1)+1个区域，所以递推公式f(n) = f(n-1) + 4 * (n-1) + 1
**2069.cpp**
    1.对于这种硬币种类达到某一数额的不同组成的题，思路就是dp[i]=dp[i-1]+dp[i-5]+dp[i-10]+dp[i-20],即某一类数额等于之前的可能到这种数额的种类之和，但是要明白的是，**这种加和不是在之前的数额已经最终确定后再相加，而是过程中相加，即两层for循环时为**
> for(k = 0; k <5; k++)
    {
        for(j = v[k]; j <= n; j++)
        {
            dp[j] += dp[j-v[k]];
        }
>   }



先一遍把dp[i-1]历一遍，再历dp[i-5]。举个例子，要得到dp[15]，因为dp[0]=1（因为没有钱也算一种方法，换个想法也相当于全是1的那种情况）第一遍时把dp[1～15]都变成1，再历dp[i-5]，从v[k]=5开始（因为如果从小于v[k]开始，没有加一个5元硬币的可能性），dp[j] += dp[j-v[k]]，dp[5～9]=2，dp[10～14]=3，dp[15]=4，再历dp[i-10]，从v[k]=10开始，dp[10～14]=4，dp[15]=6，就得到结果，可知是一次次累加的而不是用最终的dp[14]+dp[10]+dp[5]=4+4+2得到的。
其实这种思路用大脑想的话，就是开始1～15都只有一种方法，即全一，然后到5时多了一种五个一合成为一个5的方法，对应于dp[5] += dp[0]，6～9时都只是多了一种五个一合成为一个5的方法，对应于dp[6～9] += dp[1～4]，到10时多了种五个一合成为一个5（和前面一样）和两个五个一合成为两个5的方法dp[10] += dp[5]，前面的加的是1这里加的是dp[5]=2，2一个代表第一种方法，蕴含在dp[5]中，还有一个1因为10-5=5又可以多融合一个5，第二种方法。以这种方式不断增加。
2.对于这个题来说，因为它要求不超过100个硬币，所以要用dp[][]代表由i个硬币组成的j元钱的可能数，（其实只可能为1或0。。hhh），然后再加一层for循环即可