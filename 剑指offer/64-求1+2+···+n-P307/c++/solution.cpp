// Author : lihongyu
// Time   : 2019-12-19

#include<bits/stdc++.h>
using namespace std;

// 剑指offer 64-求1+2+···+n-P307 禁用递归与循环
// 思路：构造函数
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class Tmp {
public:
    Tmp(){
        ++N;
        sum += N;
    }
    static int getSum(){
        return sum;
    }
    static void reset() {
        N = 0;
        sum = 0;
    }
private:
    static int N, sum;
};

int Tmp::N = 0, Tmp::sum = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        Tmp::reset();
        auto *obj = new Tmp[n];
        delete []obj;
        obj = nullptr;
        return Tmp::getSum();
    }
};

// 思路：利用虚函数
// 时间复杂度: O(n)
// 空间复杂度: O(1)

class A;
A* Array[2];

class A {
public:
      virtual int Sum (int n) { return 0; }
};

class B: public A {
public:
      virtual int Sum (int n) { return Array[!!n]->Sum(n-1)+n; }
};

class Solution2 {
public:
    int Sum_Solution(int n) {
        A a;
        B b;
        Array[0] = &a;
        Array[1] = &b;

        return Array[1]->Sum(n);
    }
};

// 思路：函数指针 数组
// 时间复杂度: O(n)
// 空间复杂度: O(1)

typedef int (*fun)(int);

class Solution3 {
public:
    static int Sum_SolutionSup(int n){
        return 0;
    }
    static int Sum_Solution(int n) {
        fun f[2]={Sum_SolutionSup, Sum_Solution};
        return n + f[!!n](n - 1);
    }
};

// TODO：
// 思路：使用泛型，利用编译器进行递归
// 时间复杂度: O(n)
// 空间复杂度: O(1)

template <int n> struct solution4_Sum
{
      enum Value { N = solution4_Sum<n - 1>::N + n};
};


template <> struct solution4_Sum<1>
{
      enum Value { N = 1};
};

int main(){

    cout<<Solution3().Sum_Solution(5)<<endl; // 输出: 15

    return 0;
}