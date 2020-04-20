// Author : lihongyu
// Time   : 2019-12-23

#include<bits/stdc++.h>
using namespace std;

// 剑指offer 66-构建乘积数组-P312
// 思路：构建矩阵进行计算
// 时间复杂度: O(n)
// 空间复杂度: O(1)
//B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]
//从左到右算 B[i]=A[0]*A[1]*...*A[i-1]
//从右到左算B[i]*=A[i+1]*...*A[n-1]
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {

        int n=A.size();
        vector<int> b(n);
        int ret=1;
        for(int i=0;i<n;ret*=A[i++]){
            b[i]=ret;
        }
        ret=1;
        for(int i=n-1;i>=0;ret*=A[i--]){
            b[i]*=ret;
        }
        return b;
    }
};

class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1;
        int right = 1;
        int len = nums.size();
        vector<int> output = vector<int>(len);
        for(int i = 0; i < len; i++){
            output[i] = left;
            left *= nums[i];
        }
        for(int j = len-1; j >= 0; j--){
            output[j] *= right;
            right *= nums[j];
        }
        return output;
    }
};

void printVector(vector<int> &arr){

    for (int i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
}

// TODO:
int main(){

    vector<int> arr = {0, 1, 2, 3};
    vector<int> res = Solution().multiply(arr);
    printVector(res); // 输出 6 0 0 0
    vector<int> res2 = Solution2().productExceptSelf(arr);
    printVector(res2);

    return 0;
}