// Author : lihongyu
// Time   : 2019-11-06

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for (int i = 0; i < array.size();i++)
        {
            for (int j = array.size() - 1; j>i;j--)
            {
                if (array[j] % 2 == 1 && array[j - 1]%2 == 0)
                {
                    swap(array[j], array[j-1]);
                }
            }
        }
    }
};

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    Solution().reOrderArray(a);
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<endl;
    return 0;
}