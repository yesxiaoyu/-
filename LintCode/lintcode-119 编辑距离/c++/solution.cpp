// Author : lihongyu
// Time   : 2019-12-18

#include<bits/stdc++.h>
using namespace std;

// lintcode-119 编辑距离、计算字符串相似度
// 思路：《编程之美》-P224:递归
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    /**
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
    int minDistance(string &word1, string &word2) {
        // write your code here
        return StrDistanceCal(word1, 0, word1.length(), word2, 0, word2.length());
    }

private:
    int StrDistanceCal(string &word1, int l1, int r1, string &word2, int l2, int r2){
        if (l1 > r1) {
            if (l2 > r2)
                return 0;
            else
                return r2 - l2 + 1;
        }
        if (l2 > r2){
            if (l1 > r1)
                return 0;
            else
                return r1 - l1 + 1;
        }
        if (word1[l1] == word2[l2])
            return StrDistanceCal(word1, l1 + 1, r1, word2, l2 + 1, r2);
        else
            return min(min(StrDistanceCal(word1, l1, r1, word2, l2 + 1, r2),
                    StrDistanceCal(word1, l1 + 1, r1, word2, l2, r2)),
                            StrDistanceCal(word1, l1 + 1, r1, word2, l2 + 1, r2)) + 1;
    }
};

// 思路：动态规划
// 时间复杂度: O(mn)
// 空间复杂度: O(mn)

class Solution2 {
public:
    /**
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
    int minDistance(string &word1, string &word2) {
        int size1 = word1.length();
        int size2 = word2.length();

        //子串都应包含空串，所以长度都+1
        vector<vector<int> > dp(size1 + 1);
        for (int i = 0; i < size1 + 1; ++i) {
            dp[i] = vector<int>(size2 + 1, 0);
        }
        for (int i = 0; i <= size1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= size2; j++) {
            dp[0][j] = j;
        }

        //都从不为空串的第一个子串开始
        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <=size2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1;
                }
            }
        }
        return dp[size1][size2];
    }
};

// TODO：记忆化搜索

int main(){
    string s1 = "horse", s2 = "ros";
    cout<<Solution2().minDistance(s1, s2)<<endl;
    return 0;
}