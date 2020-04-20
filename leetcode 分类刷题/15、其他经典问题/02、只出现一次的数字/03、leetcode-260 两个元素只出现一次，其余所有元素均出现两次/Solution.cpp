// Author : lihongyu
// Time   : 2019-12-16

#include<bits/stdc++.h>
using namespace std;

// leetcode-260 只出现一次的数字：两个元素只出现一次，其余所有元素均出现两次
// 思路：数字电路设计的思路，与136/137题类似，
// 在136题中我们使用异或运算使得相同的两个数运算的结果为0，
// 在本题中，我们需要思考的问题是，我们是否能够定义一种运算（代替异或），使得三个数运算的结果为 0
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int Xor = 0;
		for (int c : nums)  Xor ^= c;   //全部异或的值

		int DiffNum = Xor & (~Xor + 1);//取最低为为 1 的值

		int a = 0, b = 0;

		for (int c : nums) {//将nums分为2个部分,一部分DiffNum位置为1,另外一部分DiffNum为0  恰好需要查找的a b都分别属于这2部分
			if (c & DiffNum)
				a ^= c;
			else
				b ^= c;
		}
		return { a,b };
    }
};

void printVector(vector<int>& arr){

    for (int i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
}

// TODO：电路题，没理解，参见《剑指offer》分组思路

int main(){
    vector<int> arr = {1, 2, 1, 3, 2, 5};
    vector<int> res = Solution().singleNumber(arr);
    printVector(res);
    return 0;
}