// Author : lihongyu
// Time   : 2019-12-14

#include<bits/stdc++.h>
using namespace std;

// leetcode-347 前k个高频元素
// 思路：优先队列
// 时间复杂度: O(logn)
// 空间复杂度: O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        int size = nums.size();
        unordered_map<int, int> umap;
        for (int n : nums) {
            ++umap[n];
        }
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        for (auto it = umap.begin(); it != umap.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > (int)umap.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};

void printVector(vector<int>& arr){

    for (int i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
}

// TODO：思路：对于多位大数存在重复运算，采用递归，分别统计各个位数1的个数

int main(){
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    int num = 2;
    vector<int> res = Solution().topKFrequent(arr, num);
    printVector(res);
    return 0;
}