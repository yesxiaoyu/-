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
    void PrintFromTopToBottom(TreeNode* root) {
        if (root == nullptr)    return;
        stack<TreeNode* > levels[2];
        int next_level=0, to_be_print=1;
        levels[next_level].push(root);
        while (!levels[0].empty() || !levels[1].empty()){
            TreeNode* CurNode = levels[next_level].top();
            levels[next_level].pop();
            cout<<CurNode->val<<" ";
            if(next_level == 0){
                if (CurNode->left)
                    levels[to_be_print].push(CurNode->left);
                if (CurNode->right)
                    levels[to_be_print].push(CurNode->right);
            } else{
                if (CurNode->right)
                    levels[to_be_print].push(CurNode->right);
                if (CurNode->left)
                    levels[to_be_print].push(CurNode->left);
            }
            if (levels[next_level].empty()){
                cout<<endl;
                next_level = 1 - next_level;
                to_be_print = 1 - to_be_print;

            }
        }
    }
};

int main(int argc, char* argv[])
{
    vector<int> pre = {8, 6, 5, 7, 10, 9, 11}, vin = {5, 6, 7, 8, 9, 10, 11};
    TreeNode* root = reConstructBinaryTree(pre, vin);
    postOrder(root);
    cout<<endl;

    Solution().PrintFromTopToBottom(root);

    return 0;
}
