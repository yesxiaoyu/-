// Author : lihongyu
// Time   : 2019-12-09

#include<bits/stdc++.h>
using namespace std;

// leetcode-509 斐波那契数列 Fibonacci Sequence
// 思路：递归求斐波那契数列
// 时间复杂度: O(n!)
// 空间复杂度: O(1)

//fib(42) = 267914296 可能已经溢出...
//time : 2.289 s
//run function fib() 866988873 times.

int num = 0;
class Solution {
public:

    int fib( int n ){

        num ++;
        if( n == 0 )
            return 0;
        if( n == 1 )
            return 1;
        return fib(n-1) + fib(n-2);
    }
};

// 思路：记忆化搜索
// 时间复杂度: O(n)
// 空间复杂度: O(n)

//fib(42) = 267914296
//time : 0 s
//run function fib() 83 times.

//int num = 0;
vector<int> memo;
class Solution2 {
public:

    int fib( int n ){

        num ++;
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(memo[n] == -1)
            memo[n] = fib(n - 1) + fib(n - 2);

        return memo[n];
    }
};

// 思路：动态规划
// 时间复杂度: O(n)
// 空间复杂度: O(n)

//fib(42) = 267914296
//time : 0 s
//run function fib() 0 times.

class Solution3 {
public:

    int fib( int n ){

        vector<int> memo(n + 1, -1);

        memo[0] = 0;
        memo[1] = 1;
        for(int i = 2 ; i <= n ; i ++)
            memo[i] = memo[i - 1] + memo[i - 2];

        return memo[n];
    }
};

// 思路：优化空间，数组中只保留两项
// 时间复杂度: O(n)
// 空间复杂度: O(n)

class Solution4 {
public:
    int fib(int N) {
        int tmp=0;
        vector<int> nums = {0,1};
        if(N<2) return N;
        for(int i=2;i<=N;i++){
            tmp = nums[0] + nums[1];
            nums[0] = nums[1];
            nums[1] = tmp;
        }
        return tmp;
    }
};

// 思路：通项公式
// 时间复杂度: O(logn)
// 空间复杂度: O(logn)

//fib(42) = 267914296
//time : 0 s
//run function fib() 0 times.

class Solution5 {
public:
    int fib(int N) {

        double sqrt5=sqrt(5);
        return round(pow((1+sqrt5)/2,N)/sqrt5);
    }
};

// TODO：再快就得打表了...

int main(){
//    num = 0;
    int n = 42;
//    memo = vector<int>(n + 1, -1);

    time_t startTime = clock();
    int res = Solution5().fib(n);
    time_t endTime = clock();

    cout << "fib(" << n << ") = " << res << endl;
    cout << "time : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    cout << "run function fib() " << num << " times." << endl;

    return 0;
}