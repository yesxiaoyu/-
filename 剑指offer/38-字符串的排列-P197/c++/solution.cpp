#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {

        if (str.length() == 0) return rst;
        Permutation(str, 0);
        sort(rst.begin(), rst.end());
        return rst;
    }

private:
    vector<string> rst;
    void Permutation(string str, int begin){
        if (begin == str.length()){
            rst.emplace_back(str);
            return;
        } else {
            for (int i = begin; str[i] != '\0'; ++i) {
                if(i!=begin&&str[begin]==str[i])
                    continue;
                swap(str[i], str[begin]);
                Permutation(str, begin+1);
                swap(str[i], str[begin]);
            }
        }
    }
};

int main(int argc, char* argv[])
{
    string s = "abc";
    vector<string> rst = Solution().Permutation(s);
    for (int i = 0; i < rst.size(); i++){
        cout<<rst[i]<<" ";
    }
    cout<<endl;
    return 0;
}