// Author : lihongyu
// Time   : 2019-12-07

#include<bits/stdc++.h>
using namespace std;

// 剑指offer-49 丑数
// 思路：按照顺序找到第index的整数.
// 判断是否为丑数时，即使一个数不是丑数也要对其求余以及进行除法操作，时间效率很低.
// 牛客通不过.
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution {
public:
    int GetUglyNumber_Solution(int index) {

        if (index <= 0) return 0;
        int nb = 0, uglyFound = 0;

        while (uglyFound < index){
            nb++;
            if (isUgly(nb)) uglyFound++;
        }

        return nb;
    }

private:
    bool isUgly(int num){

        while (num % 2 == 0)    num /= 2;
        while (num % 3 == 0)    num /= 3;
        while (num % 5 == 0)    num /= 5;

        return num == 1;
    }
};

// 思路：按照顺序找到第index的整数.
// 判断是否为丑数时，即使一个数不是丑数也要对其求余以及进行除法操作，时间效率很低.
// 牛客通不过.
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Solution2 {
public:
    int GetUglyNumber_Solution(int index) {

        if (index <= 0) return 0;
        vector<int> uglyNums = {1};
        int nextUglyIdx = 1, multi2 = 0, multi3 = 0, multi5 = 0;
        int mins = 1;
        while (uglyNums.size() < index) {
            mins = min(uglyNums[multi2] * 2, min(uglyNums[multi3] * 3, uglyNums[multi5] * 5));

            if (uglyNums[multi2] * 2 == mins)    multi2++;
            if (uglyNums[multi3] * 3 == mins)    multi3++;
            if (uglyNums[multi5] * 5 == mins)    multi5++;

            uglyNums.emplace_back(mins);
        }
        // 清空vector内存
//        vector<int>().swap(uglyNums);

        return mins;
    }
};

// TODO：

int main(){
    int n = 10;
    cout<<Solution2().GetUglyNumber_Solution(n)<<endl;
    return 0;
}