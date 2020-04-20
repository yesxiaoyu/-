// Author : lihongyu
// Time   : 2020-1-4

#include<bits/stdc++.h>
using namespace std;

// leetcode-392 判断子序列
// 思路：贪心
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = 0, tl = 0, sr = s.length()-1, tr = t.length()-1;
        int sn = 0;
        if (sr == -1)  return true;
        if (tr == -1) return false;
        while (sl <= sr && tl <= tr) {
            if (s[sl] == t[tl]) {
                sn++;
                sl++;
            }
            tl++;
        }
        return sn == sr + 1;
    }
};

// TODO:
int main(){
    string s = "abc", t = "ahbgdc";
    cout<<Solution().isSubsequence(s, t)<<endl;
    return 0;
}