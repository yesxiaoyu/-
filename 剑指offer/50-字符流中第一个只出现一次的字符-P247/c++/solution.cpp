// Author : lihongyu
// Time   : 2019-12-26

#include<bits/stdc++.h>
using namespace std;

// 剑指offer 50-字符流中第一个只出现一次的字符-P247
// 思路：
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
private:
    string s;
    char hash[256] = {0};
public:
    //Insert one char from stringstream
    void Insert(char ch) {
        s += ch;
        hash[ch] ++;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        int size = s.length();
        for(int i = 0; i < size; ++i) {
            if(hash[s[i]] == 1)
                return s[i];
        }
        return '#';
    }
};

// TODO:
int main(){
    auto s = new Solution();
    s->Insert('g');
    s->Insert('o');
    cout<<s->FirstAppearingOnce()<<endl;
    s->Insert('g');
    s->Insert('o');
    s->Insert('o');
    s->Insert('l');
    s->Insert('e');
    cout<<s->FirstAppearingOnce()<<endl;

    return 0;
}