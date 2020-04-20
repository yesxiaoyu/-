// Author : lihongyu
// Time   : 2019-12-06

#include<bits/stdc++.h>
using namespace std;

// 剑指offer-43 1~n整数中1出现的次数
// 思路：对10取余，累加每位为1的个数
// 时间复杂度: O(nlogn)
// 空间复杂度: O(1)

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int num = 0;
        for (int i = 1; i < n+1; ++i)
            num += NumOf1(i);
        return num;
    }

private:
    int NumOf1(int n) {
        int num = 0;
        while (n) {
            if (n % 10 == 1)
                num++;
            n /= 10;
        }
        return num;
    }
};

// TODO：思路：对于多位大数存在重复运算，采用递归，分别统计各个位数1的个数
// 时间复杂度: O(logn)
// 空间复杂度: O(1)

int main(){
    int n = 12;
    cout<<Solution().NumberOf1Between1AndN_Solution(n)<<endl;
    return 0;
}