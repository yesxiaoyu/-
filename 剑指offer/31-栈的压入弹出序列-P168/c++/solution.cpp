#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> sk;
        int i = 0, j = 0;
        while(i <= pushV.size()){
            while (sk.empty() || sk.top() != popV[j])   sk.push(pushV[i++]);
            if (sk.top() != popV[j]) return false;
            sk.pop();
            j++;
        }
        return sk.empty() && i == j;
    }
};

int main(int argc, char* argv[])
{
    vector<int> pushV = {1, 2, 3, 4, 5};
//    vector<int> popV = {4, 5, 3, 2, 1};
    vector<int> popV = {4, 3, 5, 1, 2};

    cout<<Solution().IsPopOrder(pushV, popV);

    return 0;
}