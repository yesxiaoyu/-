#include<bits/stdc++.h>
using namespace std;

// 剑指offer-39数组中出现次数超过一半的数字
// 解法一，基于patition函数
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    static int MoreThanHalfNum_Solution(vector<int>& nums) {

        int middle = nums.size() >> 1;
        int l = 0, r = nums.size()-1;
        int index = partition(nums, l, r);
        while (index != middle)
            if (index > middle)
                index = partition(nums, l, index - 1);
            else
                index = partition(nums, index + 1, r);
        if (CheckMoreThanHalf(nums, nums[index]))   return nums[middle];
        else    return 0;
    }

private:
    static int partition(vector<int>& nums, int l, int r){

        int v = nums[l];
        int j = l;
        for(int i = l + 1; i <= r; i++){
            if (nums[i] < v){
                j++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[l], nums[j]);
        return j;
    }

    static bool CheckMoreThanHalf(vector<int> nums, int n){
        int times = 0;
        for (int num : nums) {
            if(num == n)
                times++;
        }
        return times > nums.size() >> 1;
    }
};

// 解法2：基于数组特点，求出现次数比其他数字出现次数和还多的数字.
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution2{
public:
    static int MoreThanHalfNum_Solution(vector<int>& nums) {
        int res = nums[0];
        int times = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (times == 0){
                res = nums[i];
                times = 0;// 1->0
            } else if (nums[i] == res)  times++;
            else    times--;
        }
        if (CheckMoreThanHalf(nums, res))   return res;
        else    return 0;
    }

private:
    static bool CheckMoreThanHalf(vector<int> nums, int n){
        int times = 0;
        for (int num : nums) {
            if(num == n)
                times++;
        }
        return times > nums.size() >> 1;
    }
};

int main(){
    vector<int> arr = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    cout<<Solution2::MoreThanHalfNum_Solution(arr)<<endl;
    return 0;
}