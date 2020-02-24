// Author : lihongyu
// Time   : 2019-11-04

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    double PowerExponent(double base, int exp){
        if(exp == 0)    return 0;
        if(exp == 1)    return base;
        double res = PowerExponent(base, exp>>1);
        res *= res;
        if(exp & 0x1 == 1)  res *= base;
        return res;
    }

    double Power(double base, int exponent) {
        return PowerExponent(base, exponent);
    }
};

int main() {
    cout<<Solution().Power(2, 3)<<endl;
    return 0;
}

