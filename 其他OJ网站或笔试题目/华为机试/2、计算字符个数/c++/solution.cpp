#include<bits/stdc++.h>
using namespace std;

// nowcoder-huawei-2 计算字符个数
// https://www.nowcoder.com/practice/a35ce98431874e3a820dbe4b2d0508b1?tpId=37&tqId=21225&tPage=1&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking
// 时间复杂度: O(n)
// 空间复杂度: O(1)

int main(){
    string s;
    char c;
    while(cin>>s>>c){

        int count = 0;
        for(int i = s.length()-1; i >=0; --i)
            if(s[i] == c || s[i] == c+32 || s[i] == c-32)
                count++;
        cout<<count<<endl;
    }
    return 0;
}