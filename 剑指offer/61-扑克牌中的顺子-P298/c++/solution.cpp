// Author : lihongyu
// Time   : 2019-12-18

#include<bits/stdc++.h>
using namespace std;

// 剑指offer 61-扑克牌中的顺子-P298
// 思路：
// 时间复杂度: O(nlogn)~O(n)
// 空间复杂度: O(1)

class Solution {
public:
    bool IsContinuous( vector<int> &numbers ) {
        if (numbers.size() < 5)
            return false;
        // 首先把数组排序
        sort(numbers.begin(), numbers.end()); // 默认less<int>()，从小到大排序
        // 其次统计数组中0的个数
        int zeroNum = 0;
        for (int number : numbers) {
            if (number == 0)
                zeroNum++;
        }
        // 最后统计相邻元素之间空缺数，若其小于等于0的个数，则此数组连续
        int gapNum = 0;
        for (int i = zeroNum; i < numbers.size(); ++i) {
            if (i > 0 && numbers[i] == numbers[i-1])
                return false;
            if (i > zeroNum && numbers[i] - numbers[i-1] > 1)
                gapNum += numbers[i] - numbers[i-1] - 1;
        }
        return gapNum <= zeroNum;
    }
};

// TODO：

int main(){

    vector<int> arr = {1, 3, 0, 7, 0};//{0, 3, 2, 6, 4};//{0, 1, 3, 4, 5};
    cout<<Solution().IsContinuous(arr)<<endl; // 输出: 1

    return 0;
}