// Author : lihongyu
// Time   : 2019-12-06

#include<bits/stdc++.h>
using namespace std;

// 剑指offer-45 把数组排成最小的数
// 思路：为防止大数合并导致溢出，需要转换int为string
//     定义一种新的比较方式
// 时间复杂度: O(nlogn)
// 空间复杂度: O(1)

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int len = numbers.size();
        string res;
        if(len == 0) return "";
        sort(numbers.begin(), numbers.end(), cmp);
        for(int i = 0; i < len; i++){
            res += to_string(numbers[i]);
        }
        return res;
    }
private:
    static bool cmp(int a, int b) {
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;
    }
};

int main(){
    vector<int> arr = {3, 32, 321};
    cout<<Solution().PrintMinNumber(arr)<<endl;
    return 0;
}