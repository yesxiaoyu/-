// Author : lihongyu
// Time   : 2019-12-13

#include<bits/stdc++.h>
using namespace std;

// 剑指offer58-左旋转字符串-P286
// 思路：调用58-翻转字符串-P284中reverse函数3次
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.length() < 2)   return str;
        int firstStart = 0, firstEnd = n - 1, secondStart = n, secondEnd = str.length()-1;
        ReverseWord(str, firstStart, firstEnd);
        ReverseWord(str, secondStart, secondEnd);
        ReverseWord(str, firstStart, secondEnd);
        return str;
    }

private:
    void ReverseWord(string &str, int s, int e) {
        while(s < e)
            swap(str[s++], str[e--]);
    }
};

class Solution2 {
public:
    string LeftRotateString(string str, int n) {
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.begin() + str.size() - n);
        reverse(str.begin() + str.size() - n, str.end());
        return str;
    }
};


// TODO：

int main(){
    string str = ","; // "abcdefg";
    int num = 6; // 2
    cout<<Solution().LeftRotateString(str, num)<<endl;

    return 0;
}