// Author : lihongyu
// Time   : 2019-12-13

#include<bits/stdc++.h>
using namespace std;

// 剑指offer57-和为S的连续正数序列-P282
// 思路：双索引技术-滑动窗口
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > fres;
        if (sum < 3) return {};
        int l = 1, r = 2, maxL = (sum+1)/2;
        int curSum = l + r;

        while (l < maxL) {
            if (curSum == sum){
                vector<int> res = {};
                for (int i = l; i < r+1; ++i)
                    res.push_back(i);
                fres.push_back(res);
                r++;
                curSum += r;
            } else if (curSum > sum){
                curSum -= l;
                l++;
            } else {
                r++;
                curSum += r;
            }
        }
        return fres;
    }
};

void print2Vectors(vector<vector<int> >& arr){

    for (auto & i : arr) {
        for (int j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

// TODO：

int main(){
    int num = 15;
    vector<vector<int> > res = Solution().FindContinuousSequence(num);
    print2Vectors(res);

    return 0;
}