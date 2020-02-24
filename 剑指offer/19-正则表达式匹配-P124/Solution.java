// Author : lihongyu
// Time   : 2019-12-23

#include<bits/stdc++.h>
using namespace std;

// 剑指offer 19-正则表达式匹配-P124
// 思路：分情况讨论模式串第二个字符是否为*
// 当模式中的第二个字符不是“*”时：
//1、如果字符串第一个字符和模式中的第一个字符相匹配，那么字符串和模式都后移一个字符，然后匹配剩余的。
//2、如果 字符串第一个字符和模式中的第一个字符相不匹配，直接返回false。
//
// 而当模式中的第二个字符是“*”时：
//如果字符串第一个字符跟模式第一个字符不匹配，则模式后移2个字符，继续匹配。如果字符串第一个字符跟模式第一个字符匹配，可以有3种匹配方式：
//1、模式后移2字符，相当于x*被忽略；
//2、字符串后移1字符，模式后移2字符；
//3、字符串后移1字符，模式不变，即继续匹配字符下一位，因为*可以匹配多位；
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    bool match(char *s, char *p) {
        if (s == nullptr || p == nullptr)
            return false;

        if (*s == '\0' && *p == '\0')
            return true;
        if (*s != '\0' && *p == '\0')
            return false;
        if (*(p + 1) == '*') {
            if (*p == *s || (*p == '.' && *s != '\0'))
                return match(s + 1, p + 2) || match(s + 1, p) || match(s, p + 2);
            else
                return match(s, p + 2);
        }
        if (*s == *p || (*p == '.' && *s != '\0'))
            return match(s + 1, p + 1);
        return false;
    }
};



// TODO:
int main(){

    char str[] = "aaa", pattern[] = "a*";
    cout<<Solution().match(str, pattern)<<endl;

    return 0;
}