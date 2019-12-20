// Author : lihongyu
// Time   : 2019-12-19

#include<bits/stdc++.h>
using namespace std;

// 剑指offer 67-把字符串转换成整数-P318
// 思路：
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    int StrToInt(string str) {
        int pre = 1, res = 0;
        int flag = str[0] == '-' ? -1 : 1;
        for (int i = str.length() - 1; i >= 0; --i) {
            if (str[i] >= '0' && str[i] <= '9') {
                res += (str[i] - '0') * pre;
                pre *= 10;
                cout<<res<<endl;
                if ( ((str[0] != '-') && (res > 0x7FFFFFFF)) ||
                        ((str[0] == '-') && (res > 0x80000000)) ||
                   ((str[0] != '-') && (res == 0x80000000))) {
                    return 0;
                }
            } else {
                if ((str[0] == '-' && i == 0) || (str[0] == '+' && i == 0))
                    continue;
                else
                    return 0;
            }
        }
        return str[0] == '-' ? -res : res;
    }
};

// TODO:
int main(){

    string s = "-2147483649"; // "-123";"2147483648"; //
    cout<<Solution().StrToInt(s)<<endl; // 输出: 123

    return 0;
}