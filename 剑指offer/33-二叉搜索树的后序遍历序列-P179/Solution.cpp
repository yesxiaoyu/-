#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {

        return VeryBST(sequence, 0, sequence.size());
    }

private:
    bool VeryBST(vector<int> sequence, int begin, int end){

        if (sequence.empty() || begin > end-1)
            return false;
        int root = sequence[end-1];
//        二叉搜索树中，左子树节点的值小于根节点的值
        int i = begin;
        for (; i < end - 1; ++i) {
            if (sequence[i] > root) break;
        }
//        二叉搜索树中，右子树节点的值大于根节点的值
        int j = i;
        for (; j < end - 1; ++j) {
            if (sequence[j] < root) return false;
        }
//        判断左子树是不是二叉搜索树
        bool left = true;
        if (i > begin)  left = VeryBST(sequence, begin, i);
//        判断右子树是不是二叉搜索树
        bool right = true;
        if(i < end - 1)  right = VeryBST(sequence, i, end-1);

        return (left && right);
    }
};

int main(int argc, char* argv[])
{
    vector<int> post = {5, 7, 6, 9, 11, 10, 8};

    cout<<Solution().VerifySquenceOfBST(post);

    return 0;
}
