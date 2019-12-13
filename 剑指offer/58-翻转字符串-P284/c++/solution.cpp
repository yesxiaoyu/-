// Author : lihongyu
// Time   : 2019-12-13

#include<bits/stdc++.h>
using namespace std;

// 剑指offer58-翻转单词顺序列-P284
// 思路：两次翻转字符串
// 时间复杂度: O(n)
// 空间复杂度: O(1)

/**
 * 利用string属性
 */
class Solution {
public:
    string ReverseSentence(string str) {
        string res;
        int len = str.length();
        int pos = 0;
        for(int i=len-1;i>=0;i--) {
            pos++;
            if(' '==str[i]) {
                res.append(str.substr(i+1,pos-1));
                res.append(" ");
                pos = 0;
            }
        }
        res.append(str.substr(0,pos));
        return res;
    }
};

/**
 * 两次翻转字符串
 */
class Solution2{
public:
    //翻转str从s到e的部分
    void ReverseWord(string &str, int s, int e) {
        while(s < e)
            swap(str[s++], str[e--]);
    }

    string ReverseSentence(string str) {
        ReverseWord(str, 0, str.size() - 1); //先整体翻转
        int s = 0, e = 0;
        int i = 0;
        while(i < str.size()) {
            while(i < str.size() && str[i] == ' ') //空格跳过
                i++;
            e = s = i; //记录单词的第一个字符的位置
            while(i < str.size() && str[i] != ' ') { //不是空格 找单词最后一个字符的位置
            
                i++;
                e++;
            }
            ReverseWord(str, s, e - 1); //局部翻转
        }
        return str;
    }
};

// TODO：思路：从前往后扫描字符串，遇到是单词就入vector，最后反向输出即可

int main(){
    string str = "student. a am I";
    cout<<Solution2().ReverseSentence(str)<<endl;

    return 0;
}