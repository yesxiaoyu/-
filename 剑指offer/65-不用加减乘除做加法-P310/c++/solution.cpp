// Author : lihongyu
// Time   : 2019-12-19

#include<bits/stdc++.h>
using namespace std;

// 剑指offer 65-不用加减乘除做加法-P310
// 思路：位运算
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    int Add(int num1, int num2) {
        int sum, carry;
        do {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;
            num1 = sum;
            num2 = carry;
        } while (num2 != 0);

        return num1;
//        return ((num1 ^ num2) + ((num1 & num2) << 1));
    }
};

// TODO: 不理解循环
int main(){

    cout<<Solution().Add(2, 3)<<endl; // 输出: 5

    return 0;
}