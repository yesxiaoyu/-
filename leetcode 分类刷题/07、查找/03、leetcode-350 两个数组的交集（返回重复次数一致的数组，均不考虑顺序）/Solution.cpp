// Author : lihongyu
// Time   : 2019-12-10

#include<bits/stdc++.h>
using namespace std;

void printMap(map<int, int>& maps){
//    for (map<int,int>::iterator iter = maps.begin(); iter != maps.end() ; iter++) {
    for (auto & iter : maps) {
        cout << iter.first << " ， " << iter.second << " ";
    }
    cout<<endl;
}

// leetcode-350 两个数组的交集（返回重复次数一致的数组，均不考虑顺序）
// 思路：将一个数组借用set去重，若另一个数组存在与set中相同元素，且结果数组中未出现，则添加到结果数组中
// 时间复杂度: O(logn)
// 空间复杂度: O(1)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> maps;
        vector<int> res;
        for (int num : nums1) {
            if (!maps.count(num))   maps.insert(map<int, int>::value_type(num,1));
            else maps[num]++;
        }
//        printMap(maps);
        for (int num : nums2) {
            if (maps.count(num))
                if (maps[num] != 0){
                    maps[num]--;
                    res.emplace_back(num);
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



// TODO：

int main(){
    vector<int> arr1 = {1, 2, 2, 1};//{4, 9, 5};
    vector<int> arr2 = {2, 2};//{9, 4, 9, 8, 4};
    vector<int> res = Solution().intersect(arr1, arr2);
    printVector(res);
    return 0;
}