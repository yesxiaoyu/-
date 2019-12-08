// Author : lihongyu
// Time   : 2019-12-08

#include<bits/stdc++.h>
using namespace std;

// 剑指offer-50 第一个只出现一次的字符
// 思路（理解有问题，之前也不能出现相同字符）：
// 当访问到某个字符时，与后面每个字符比较，如果未发现重复字符，则该字符为只出现一次的字符.
// 牛客网通不过.

// 时间复杂度: O(n2)
// 空间复杂度: O(1)

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        for (int i = 0; i < str.length(); ++i) {
            for (int j = i + 1; j < str.length(); ++j) {
                if (str[i] == str[j])
                    break;
                if (j == str.length()-1)    return i;
            }
        }
        return -1;
    }
};

// 思路：可以考虑使用哈希表或者单独字符数组，空间换时间

// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution2 {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty())
            return -1;
        vector<char> ch = vector<char>(256, 0);
        for(char i : str)
            ch[i]++;
        for(int i = 0; i<str.length(); i++)
            if(ch[str[i]]==1)
                return i;
        return 0;
    }
};

// TODO：

int main(){
    string s = "google";//"abaccdeff";
    cout<<Solution2().FirstNotRepeatingChar(s)<<endl;
    return 0;
}