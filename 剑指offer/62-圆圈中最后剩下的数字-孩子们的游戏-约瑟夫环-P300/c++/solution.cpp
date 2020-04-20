// Author : lihongyu
// Time   : 2019-12-18

#include<bits/stdc++.h>
using namespace std;

// 剑指offer 61-扑克牌中的顺子-P298
// 思路：环形链表
// 时间复杂度: O(mn)
// 空间复杂度: O(n)

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if (n < 1 || m < 1)
            return -1;
        list<int> nums;
        for (int i = 0; i < n; ++i) {
            nums.push_back(i);
        }

//        cout << "mylist contains:";
//        for (int & num : nums)
//            std::cout << ' ' << num;
//        cout << '\n';

        auto current = nums.begin(); // list<int>::iterator
        while (nums.size() > 1) {
            for (int i = 1; i < m; ++i) {
                current++;
                if (current == nums.end())
                    current = nums.begin();
            }
            auto next = ++current;
            if (next == nums.end())
                next = nums.begin();
            --current;
            nums.erase(current);
            current = next;
        }
        return *(current);
    }
};


// 思路：环形链表
// 时间复杂度: O(mn)
// 空间复杂度: O(n)

class Solution2 {
public:
    int LastRemaining_Solution(int n, int m) {
        if (n < 1 || m < 1)
            return -1;
        int last = 0;
        for (int i = 2; i <= n; ++i)
            last = (last + m) % i;
        return  last;
    }
};

class Solution3 {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n == 0)
            return -1;
        if(n == 1)
            return 0;
        else
            return (LastRemaining_Solution(n-1, m) + m) % n;
    }
};

// TODO：

int main(){

    cout<<Solution().LastRemaining_Solution(5, 3)<<endl; // 输出: 3

    return 0;
}