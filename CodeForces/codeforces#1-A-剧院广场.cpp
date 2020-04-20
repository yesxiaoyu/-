// Author : lihongyu
// Time   : 2019-12-15

#include<bits/stdc++.h>
using namespace std;

// codeforces#1-A-剧院广场
// 思路：答案= ceil（m / a）* ceil（n / a），其中ceil（x）是大于或等于x的最小整数。
// 仅使用整数，通常将其写为（（m + a-1）/ a）*（（n + a-1）/ a）。
// 请注意，答案可能高达10 ^ 18，不适合32位整数
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    long long getNum(long long m, long long n, long long a) {
        long long  sum=0;
        int b1=0,b2=0;
        if(n % a) b1=1;
        if(m % a) b2=1;
        sum=(n / a + b1) * (m / a + b2);
        return sum;
    }
};

class Solution2 {
public:
    long long getNum(long long m, long long n, long long a) {
        long long t=1;
        if(m<=a||n<=a)
            t*=1;
        if(m>a){
            if(m%a==0)
                t*=m/a;
            else t*=m/a+1;
        }
        if(n>a){
            if(n%a==0)
                t*=n/a;
            else t*=n/a+1;
        }
        cout<<t<<endl;
        return t;
    }
};
// TODO：

int main(){

    long long m,n,a;
    cin>>m>>n>>a;
    cout<<Solution().getNum(m, n, a)<<endl;
    return 0;
}