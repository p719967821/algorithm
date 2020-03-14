 ## 如果认为正确，仍不能ac要想到的几个可能的问题<font color ="red">
1.int不够，导致溢出，要换用long long
2.数据类型不对，注意是要用int还是double
3.对于全句重复使用的数是否在再次使用之前初始化了
4.对于map函数，如果map<int,int> p， p[a]=b;此时b=3,如果变成b=4，p[a]不会改变，因为对应的是b的值而不是b，只有p[a]=4这种形式才会改变数据大小。
5.代码整体左右移动的方法，选中要移的部分，按tab键是整体右移，tab+shift键是整体左移
</font>

***

**1200.cpp**
    问题的关键就是排序的方式。
    1.注意在思考时可以用特殊值，但是在推导公式时一定要用未知数表示
    2.竖着输出时，既然i，j两层循环的位置都变了，那么x[i][j]就应保持不变，不能写成x[j][i]
**1201.cpp**
    string的部分使用方法
    1.形成一个指针及string型变int型方法
    如string s=“123”要形成一个指向该字符串的指针只用s.c_str()，它就是一个指针，
    使用时：比如说我想把s变成int型要用到atoi()函数，但是函数中参数必须是s的指针，不能直接是s，所以要写成
    int si = atoi(s.c_str());
    (另外如果字符串是03，变成int自动变成3)
    闰年：年份能被四整除且不能被一百整除，或者能被400整除
**2000.cpp**
    1.EOF的使用
    EOF只在用在c中，如果要用在c++中，要加头文件 #include <stdio.h>,它可以看成一个定值-1，意思是文件输入结束或者函数错误，所以一般在使用时为 XXX!= EOF.在c++中就直接用while(cin >> a),如果输入成功就循环，输入失败或者没有输入就跳出循环
    2.要明白while(cin >> a)一般来说只要是输入成功不管a为什么数，逻辑值都认为是1，都要执行{}中的内容。另外一种while(cin >> a,a)或while(cin >> a && a)此时才是想的输入为0是跳出循环，不为0是进入循环。
**2001.cpp**
    1.scanf和printf在c中，是在<stdio.h>中的。
    2.关于c++中的输入输出问题看书，setw(),setprecision(),left,right...
    3.虽然题目的输入是int，但是可以直接代码时就用double，输入整数后他会自己隐式转换成double，不用再显示转化一遍
**2005.cpp**
    1.  switch函数中case后面只能接常数不能接表达式  case 7:(right) case(x+3):(wrong) case(x <=5 && x >3):(wrong))
    2.  1999/11/11这种输入时，不用很麻烦的输入字符再转化成int，可以直接用scanf的("%d/%d/%d",&a,&b,&c)（详细见书本），但是c++中的cin没有对应的功能
**2006.cpp**
    1. 有多次平行数据时，全局变量在一次数据用完后一定记得初始化
**2007.cpp** 
    1.坑啦。。他说的一段数没有说顺序，可能前大后小，这个要注意
**2010.cpp**
    1.输出时要注意如果是cin >> a >> " ",输出多个数时很容易pe，所以有一种方法，即第一个数输出时cin >> a;后面的变成cin >> " " >> a;就可以了。
**2011.cpp**
    1
>   int main()
    {
    double a;
    int c,d;
    c = 7;
    d = 3;
    a = c / d; 
    return 0;
>   }

    此时a=2，其得到过程是7/3=2，2再隐式转化为double，还是2，不会为2.333
**2024.cpp**
    1.string函数在接受输入时不会接受空格，如输入’sad  sad‘，则string s=’sad‘。所以可以用getline函数
        getline函数用法
        1）头文件为#include <istream> 的cin.getline()函数，其参数有三个，如cin.getline(m,5,'a');第一个参数是接收的量，第二个是接受的数量，第三个是停止的位置,可以不填,不填则默认为'\0'.函数可以接收空格，如输入'asdaf asd',(m,4)因为最后默认'\0'所以m='asd'.(m,20)则m='asdaf asd',如果(m,5,'d'),m='as'
        2)头文件是#include <string>的getline()函数,参数两个,第一个是cin,固定,第二个就是接收的变量(string型)
        3)[参考](https://www.cnblogs.com/AndyJee/p/3821067.html)
    2.这个题的关键就是知道C语言合法标识符是什么.只能有数字,字母或下划线,且首字母不为数字    
**2030.cpp**
    1.string类可以接收汉字,但是一个汉字占两个字节,而且a每个字节sc2码都小于0,理论上是两个字节,但是在实际输出时我验证的是三个
**2034.cpp**
    1.集合的减法就是如果两个集合A,B,A-B结果为属于A但不属于B的数的集合
**2036.cpp**
    1.多边形面积公式：n边形，依次输入n个顶点，x1,y1,x2,y2,x3...s =((x1*y2-x2 *y1)+(x2 * y3-x3 *y2)+...+(xi * y(i+1)-x(i+1) *yi)) / 2;
    <font color="red">倒数第二个点的下一个点是第一个点，所以不能直接代公式，要单独分析 </font>
**2041.cpp**
    1.查看代码运行时间
        头文件是#include <time.h>,变量clock_t stime,etime;再在代码开始和结束处调用函数，stime = clock();etime = clock();
        static_cast <double>(etime-stime)/CLOCKS_PER_SEC*1000即为代码运行时间。单位是ms。
    2.深搜真的很费时间，见图片1.png左边是深搜，右边是几个for循环，左边时间是右边的几乎1000倍，所以时间范围较紧时，不要用深搜。
**2045.cpp**
    1.找到递推的规律很重要，一般方法就是可以列出来几个实验，找出其中的规律，还有就是记住动态规划的思想，每一步都是由上一步经过某种变化来的。
    2.这个题的规律就是一位置，三种，后面每位置两种，只用注意最后一个不要和第一个重合就好。讨论最后一位置。把过程中的每一位置都看成最后一位置可知，与第一个颜色不重合的个数=上一位中与第一个颜色重合的个数（因为会分成与第一个颜色不重合的两个数）*2+与第一个颜色不重合的个数（因为会分成一个与第一个颜色重合的个数，一个与第一个颜色不重合的个数）       与第一个颜色重合的个数=上一位与第一个颜色不重合的个数
    3.一般这种递推，范围很大时，最终的数据就会很大，int不够，就要记得用long long
**2046.cpp**
    1.关于递推的话，大概也就是两种思路
        “现在有n块，想想这些情况与n-1块、n-2块……时的情况有什么关系”
        “现在有n-1块，如果新增一块会新增哪些情况”
**2047.cpp**
    1.与2045题类似两种思路，
      一个是分开，分为末尾是o和非o的两类，然后根据不能oo的条件加，与2045的相加方法类似
      第二种就是直接寻找合在一起时前后项之间的规律，对于f（n）来说是f（n-1）加了eof得到的。但是要注意，当加的是ef是无所谓，即f（n-1）* 2，当加的是o时，则f（n-1）一定是e或者f，所以是f（n-2）基础上加了eo和fo，为f（n-2）* 2，所以f（n）=（f（n-1）+ f（n-2））*2
      用公式表示为：
      <font color = "red">
      n位数的总情况=
      n-1位中最后一位是o的部分*2（二代表e，f）+ n-1位中最后一位不是o的部分 *3（二代表e，o，f）
      = n-1位中最后一位是o的部分 *2 + n-1位中最后一位不是o的部分 *2+n-1位中最后一位不是o的部分 *1
      =n-1位总情况 *2 + n-1位中最后一位不是o的部分 *1
      = n-1位总情况 *2 + n-1位中最后一位不是o的部分 *1
      ***因为n-1位数的总情况=n-2位中最后一位是o的部分 * 2+ n-2位中最后一位不是o的部分 * 3，其中能让n-1的结尾不是o的有n-2位中最后一位是o的部分 *2 + n-2位中最后一位不是o的部分 * 2，合并一下即为n-2位总情况 * 2，所以***
      =n-1位总情况 *2 + n-2位总情况 * 2
      </font>
**2049.cpp**
    1.贪心已经排除了，因为我发现，开始的时候我只是把倒数第一个站点作为终点去考虑，题目中给的测试数据只有三个，当让是能过的，但是当站点比这多时，这样做就行不通了，我们只有把每个站点都作为一次终点去考虑，求乌龟到改点时的最快速度，最后将这个最好的状态一直往后面推，那么就可以得出最后的站点也是最优时间了。（贪心与dp的区别，看了有一些感触）
    2.要让int数据以double型计算时，可以在算式中乘一个1.0，因为在算式中只要有一个double，int与double混合时都会隐式转化为double计算。 
    3.https://blog.csdn.net/iwts_24/article/details/79306541
**2050.cpp**
    1.递推的关键是数学问题，要知道对于直线分割平面问题，第n条直线与之前的直线最多有n-1个交点，最多会新产生(n-1)+1个区域。因此折线可以类比，第n条折线与之前的折线最多有2*2(n-1)个交点，最多会新产生2 *2(n-1)+1个区域，所以递推公式f(n) = f(n-1) + 4 * (n-1) + 1
**2062.cpp**
    1.做这个没有思路，在网上看了教程后，自己写出来的，[教程](https://blog.csdn.net/wangke1998/article/details/80781122)，就是一个递归，关键是按字典序排列，在n个数构成的集合中的位置
    2.比较坑的一点就是f在n很大是已经超出了限度，要用long long
**2063.cpp**
    1.[教程1](https://blog.csdn.net/cillyb/article/details/55511666)[教程2](https://blog.csdn.net/qq_41727666/article/details/83825871)具体自己分析在代码中以标示
    2.
**2066.cpp**
    1.floyd算法，可以求有向图或者无向图中任意两点之间的最小距离，而且有一点要注意就是三重循环后得到的g[i][j]（i，j之间的距离），就是i到j之间最小距离，而不是说还要把两点之间的中间点的距离再加上。
    2.djstra算法的运算方法：
        1）要设set[i] , dis[i]，g[i][j]分别代表是否在扩展的圈内和到起始点的距离和i，j之间的权值
        2）初始化，先dis[i]=g[start][i],没有的用最大值表示，set全为0，再把set[start]=1
        3）开始纳入其他的点，共要纳入n-1次（用for），
            在每一次中for循环找出dis最小的，set[i]=1,修改其他的点，一个for循环修改，如果dis[j]>dis[i]+g[i][j]则dis[j]=dis[i]+g[i][j]
        4) 纳入所有点后dis即为起始点到其他各点的最小距离
        5）如果要求路径，则还要加入一个path[]
    3.这个题不能用floyd算法，O(n^3),超时了orz，只能用dijstra算法，O(n^2)
**2068.cpp**
    1.错位排序：即改变数组a[i]=i，使每个数的数值与其位置都不相等
        f(n) = (n-1)(f(n-1)+f(n-2))
        理解：【1方法理解】要改变当然从每个数的数值与其位置都相等的初始位置开始改变，当某一位置的数变到其他的n-1个位置中的一个如i位置时（共n-1种情况，所以要乘n-1），而恰好i位置的数也变到第一个数的位置，就可以把这两个位置挖去看剩下的位置，还是每个数的数值与其位置都相等，所以相当于f(n-2),得到了(n-1)f(n-2)，另一种情况i位置的数变到的不是第一个位置，此时i位置的数不能到第一个数的位置，这也等同于每个数的数值与其位置不能相等，所以从整体上看，把第一个数变到的i位置去掉，剩下的n-1个错排，得到f(n-1)
        【2方法理解】n个数的错排都是由n-1个数的错排得到的，所以假设此时已经有了n-1个数错排，将第n个数往中间放，n-1个数有n个空，但是它不能放在n空，所以它有n-1种放法。得到(n-1)f(n-1),但是这不是全部，其实还有一部分情况是举个例子说明n=4，f(3)=2,分别为2 3 1 和3 1 2，3 2 1不是，但是当放4时4 3 2 1就可以，即三个时不行，当加第四个时，那三个位置挪动，变成可以了。这一部分就是(n-1)f(n-2)
        [参考](https://blog.csdn.net/qq_18661257/article/details/47663825)
    2.__int 64(注意左边杆是两条下划线组成的))与long long的取值范围是相同的 -922亿亿左右～922亿亿左右， 但是前者在vscode中用不了，只能用后者
    (增：我发现了在vscode中有__int 64的用法只是写法不一样，为int64_t)
    3.在排列组合时一定要注意，要化到最简再计算不然就算用long long也不够，比如说c几几时，不要用Cmn=n!/((n-m)!*m!),这样十有八九超限，所以用平时手算时的那种方法更好
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
**2076.cpp**
    1.注意对于时种来说时针会受分针和秒针一起的影响。
    2.输入的时针有坑，可能大于12所以要求 %=
    3.取小数的整数部分，可以用abs(x-0.5)
**2078.cpp**
    1.注意这种题最大就是差距最远的那个。第二次遇见了，应该懂我的意思吧，，，hhh
**2080.cpp**
    1.acos函数就是用来求反三角函数的，但是得到的值为弧度值，要转化为角度值得*180.0/pi.
    2.求角度时记得正弦余弦函数