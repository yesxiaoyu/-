// Author : lihongyu
// Time   : 2019-11-02

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int NumberOf1(int n) {
         int count = 0;
         int flag = 1;

         while (flag){
             if(n & flag)
                 count++;
             flag = flag << 1;
         }
         return count;
     }
     
     int NumberOf12(int n) {
         int count = 0;
         
         while (n){
            count++;
            n = (n-1) & n;
         }
         return count;
     }
};

int main() {
    cout<<Solution().NumberOf12(9)<<endl;
    return 0;
}