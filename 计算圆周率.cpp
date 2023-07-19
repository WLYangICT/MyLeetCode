//假设题目要求就是计算圆周率，要求精度到1e-6(0.000001)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //利用公式 Π  = 4 * (1 - 1/3 + 1/5 - 1/7......)
    float flag = 1;  //标识正负
    double m = 1;  //标识
    double pi = 0;
    for(int i = 1; i <= 1e6; i++)
    {
        pi += flag * 1.0 / m;
        flag *= -1;
        m += 2;
    }
    pi *= 4.0;
    cout << pi;
    return 0;
}