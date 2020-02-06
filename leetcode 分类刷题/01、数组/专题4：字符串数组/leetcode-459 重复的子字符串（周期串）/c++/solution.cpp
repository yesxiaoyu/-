// Author : lihongyu
// Time   : 2019-12-23

#include<bits/stdc++.h>
using namespace std;

// leetcode-459 重复的子字符串
// 思路：周期串
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length(), i = 0;
        for(int t = 1; t <= len/2; ++t) {
            if (len % t != 0)
                continue;    // 有余数,一定不为周期串
            for (i = t; i < len && (s[i % t] == s[i]); ++i);
            if (i == len)
                return true;
        }
        return false;
        // return (s + s).find(s, 1) != s.size();
    }
};

// TODO:
int main(){

    string str = "abab" ;
    cout<<Solution().repeatedSubstringPattern(str)<<endl;

    return 0;
}