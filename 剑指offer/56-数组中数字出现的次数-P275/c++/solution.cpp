// Author : lihongyu
// Time   : 2019-12-12

#include<bits/stdc++.h>
using namespace std;

// 剑指offer-56 数组中数字出现的次数
// 思路：分组，任何一个数字异或自身都为0
// 时间复杂度: O(n)
// 空间复杂度: O(1)

/**
 * 两个相同数字异或=0，一个数和0异或还是它本身。
 */
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
        if(data.size() < 2)
            return;

        int resultExclusiveOR = 0;
        for(int i : data){
            resultExclusiveOR ^= i;
        }

        unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

        *num1 = *num2 = 0;
        for(int j : data){
            if(IsBit1(j, indexOf1))
                *num1 ^= j;
            else
                *num2 ^= j;
        }

    }

private:
    static unsigned int FindFirstBitIs1(int num){
        int indexBit = 0;
        while(((num & 1) == 0) && (indexBit < 8*sizeof(int))){
            num = num >> 1;
            indexBit++;
        }

        return indexBit;
    }

    static bool IsBit1(int num, unsigned int indexBit){
        num = num >> indexBit;
        return (num&1);
    }

};
// TODO：

int main(){
    vector<int> arr = {2, 4, 3, 6, 3, 2, 5, 5};
    int res1, res2;
    Solution().FindNumsAppearOnce(arr, &res1, &res2);
    cout<<res1<<" "<<res2<<endl;
    return 0;
}