// Author : lihongyu
// Time   : 2019-12-17

#include<bits/stdc++.h>
using namespace std;

// leetcode-153 寻找旋转排序数组中的最小值
// 思路：是否考虑重复元素？
// 时间复杂度: O(logn)
// 空间复杂度: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0,  r = nums.size() - 1;
        int m = l;
        if (nums[l] < nums[r]) return nums[l];
        while(r >= l){
        	if(r - l == 1){
        		m = r;
        		break;
			}
        	m = (l + r) / 2;

        	//如果l, m, r指向的三个数相等，则只能顺序查找

			if(nums[l] == nums[r]
				&& nums[m] == nums[l])
				return MinInOrder(nums, l, r);
			if(nums[m] >= nums[l])
				l = m;
			else if(nums[m] <= nums[r])
				r = m;
		}
		return nums[m];
    }

    int MinInOrder(vector<int> rotateArray, int l, int r){
    	int res = rotateArray[l];
    	for(int i = l + 1; i <= r; i++){
    		if(res > rotateArray[i])	res = rotateArray[i];
		}
		return res;
    }
};

// 经过旋转后的数组具有一个性质，最小值之后的所有元素都是小于等于数组最后的元素的。
// 利用这个性质可以进行二分。
class Solution2 {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] <= nums.back()) r = mid;
            else l = mid + 1;
        }

        return nums[l];
    }
};

// 最小值之后的所有元素另一个性质是都小于第一个元素。
// PS：但是数组没有旋转的时候不满足此性质，需要特判。
// (数组以第一个元素为轴旋转，等于没有旋转)
class Solution3 {
public:
    int findMin(vector<int>& nums) {
        if (nums.front() < nums.back()) return nums.front();  // 特判没有旋转的情况

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums.front()) r = mid;
            else l = mid + 1;
        }
        return nums[l];
    }
};

// TODO：

int main(){
    vector<int> arr = {1, 2};//{4, 5, 6, 7, 0, 1, 2};
    cout<<Solution2().findMin(arr)<<endl;
    return 0;
}