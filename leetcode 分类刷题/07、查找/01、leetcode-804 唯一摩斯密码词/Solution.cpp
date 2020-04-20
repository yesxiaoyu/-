// Author : lihongyu
// Time   : 2019-12-07

#include<bits/stdc++.h>
using namespace std;

// leetcode-804 唯一摩斯密码词
// 思路：使用集合set过滤重复摩斯密码
// 时间复杂度: O(nlogn)
// 空间复杂度: O(n)

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> set;

        for (string word : words) {
            string res = "";
            for (char i : word)
                res += codes[i - 'a'];
            set.insert(res);
        }
        return set.size();
    }
};

// TODO：

int main(){
    vector<string> arr = {"gin", "zen", "gig", "msg"};
    cout<<Solution().uniqueMorseRepresentations(arr)<<endl;
    return 0;
}