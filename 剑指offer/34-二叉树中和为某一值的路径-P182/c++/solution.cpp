#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
};

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    vector<int> left_pre, right_pre, left_vin, right_vin;

    if(vin.size() == 0){
        return nullptr;
    }

    //创建根节点，根节点肯定是前序遍历的第一个数
    TreeNode* root = new TreeNode(pre[0]);

    //找到中序遍历根节点所在位置
    int r = 0;
    for(int i = 0; i < vin.size(); i++){
        if(vin[i] == pre[0]){
            r = i;
            break;
        }
    }

    for(int i = 0; i < r; i++){
        left_pre.push_back(pre[i+1]);
        left_vin.push_back(vin[i]);
    }

    for(int i = r+1; i < vin.size(); i++){
        right_pre.push_back(pre[i]);
        right_vin.push_back(vin[i]);
    }

    root->left = reConstructBinaryTree(left_pre, left_vin);
    root->right = reConstructBinaryTree(right_pre, right_vin);

    return root;
}

void postOrder(TreeNode* root){

    if(root == nullptr)	return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode *root, int expectNumber) {

        if (root == nullptr) return rst;
        path.push_back(root->val);
        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if (root->val == expectNumber && isLeaf)    rst.push_back(path);
        if (root->left != nullptr) FindPath(root->left, expectNumber-root->val);
        if (root->right != nullptr) FindPath(root->right, expectNumber-root->val);
        if (!path.empty())   path.pop_back();
        return rst;
    }

private:
    vector<vector<int> > rst;
    vector<int> path;
};

void printvector2d(vector<vector<int> > v){
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char* argv[])
{
    vector<int> pre = {10, 5, 4, 7, 12}, vin = {4, 5, 7, 10, 12};
    TreeNode* tree = reConstructBinaryTree(pre, vin);

    postOrder(tree);
    cout<<endl;
    vector<vector<int> > res;
    res = Solution().FindPath(tree, 22);
    printvector2d(res);
    return 0;
}
