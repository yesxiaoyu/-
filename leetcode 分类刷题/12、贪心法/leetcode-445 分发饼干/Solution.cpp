// Author : lihongyu
// Time   : 2020-1-4

#include<bits/stdc++.h>
using namespace std;

// leetcode-445 分发饼干
// 思路：贪心
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        int gi = g.size() - 1, si = s.size() - 1;
        if (gi==-1 || si==-1)   return 0;
        sort(g.begin(), g.end());// less<int>()/greater
        sort(s.begin(), s.end());

        while (gi >=0 && si >= 0) {
            if (g[gi] <= s[si]){
                res++;
                si--;
            }
            gi--;
        }
        return res;
    }
};

// TODO:
int main(){
    vector<int> g = {10, 9, 8, 7}, s = {5, 6, 7, 8};
    cout<<Solution().findContentChildren(g, s)<<endl;
    return 0;
}