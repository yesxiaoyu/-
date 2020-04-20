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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)    return res;
        queue<TreeNode* > qroot;
        qroot.push(root);
        while (!qroot.empty()){
            TreeNode* CurNode = qroot.front();
            qroot.pop();
            res.push_back(CurNode->val);
            if (CurNode->left)  qroot.push(CurNode->left);
            if (CurNode->right) qroot.push(CurNode->right);
        }
        return res;
    }
};

void print_vector(vector<int> r){
    for (int i = 0; i < r.size(); ++i) {
        cout<<r[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, char* argv[])
{
    vector<int> pre = {8, 6, 5, 7, 10, 9, 11}, vin = {5, 6, 7, 8, 9, 10, 11};
    TreeNode* root = reConstructBinaryTree(pre, vin);
    postOrder(root);
    cout<<endl;

    vector<int> res = Solution().PrintFromTopToBottom(root);

    print_vector(res);

    return 0;
}
