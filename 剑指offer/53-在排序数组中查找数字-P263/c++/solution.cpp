// Author : lihongyu
// Time   : 2019-12-10

#include<bits/stdc++.h>
using namespace std;

// 剑指offer-53 在排序数组中查找数字
// 思路：递归使用二分查找法
// 时间复杂度: O(logn)
// 空间复杂度: O(1)

class Solution {
public:
    int GetNumberOfK(vector<int> data , int k) {
        int res_num = 0;

        int firstK = GetFirstK(data, k, 0, data.size()-1);
        int lastK = GetLastK(data, k, 0, data.size()-1);
        if (firstK > -1 && lastK > -1)  res_num = lastK - firstK + 1;
        return res_num;
    }

private:
    int GetFirstK(vector<int> vector, int k, int l, int r) {
        if (l > r) return -1;
        int mid = l + (r - l) / 2;
        if(vector[mid] == k){
            if (mid == 0 || (mid > 0 && vector[mid-1] != k)) return mid;
            else r = mid - 1;
        } else if (vector[mid] > k) r = mid - 1;
        else    l = mid + 1;
        return GetFirstK(vector, k, l, r);
    }

    int GetLastK(vector<int> vector, int k, int l, int r) {
        if (l > r) return -1;
        int mid = l + (r - l) / 2;
        if(vector[mid] == k){
            if (mid == vector.size()-1 || (mid < vector.size()-1 && vector[mid+1] != k)) return mid;
            else l = mid + 1;
        } else if (vector[mid] > k) r = mid - 1;
        else    l = mid + 1;
        return GetLastK(vector, k, l, r);
    }
};

// TODO：直接使用二分查找法时间复杂度会退化
// 时间复杂度: O(n)
// 空间复杂度: O(1)

int main(){
    vector<int> arr = {1, 2, 3, 3, 3, 3, 4, 5};
    int n = 3;
    cout<<Solution().GetNumberOfK(arr, n)<<endl;
    return 0;
}