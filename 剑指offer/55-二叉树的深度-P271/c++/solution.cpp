// Author : lihongyu
// Time   : 2019-12-12

#include<bits/stdc++.h>
using namespace std;

// 剑指offer-55 二叉树的深度
// 思路：按照是否存在左右子树，分为四种情况，分别讨论
// 时间复杂度: O(n)
// 空间复杂度: O(1)


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
};

TreeNode* Deserialize(string data) {
    if(data.empty()){return nullptr;}
    string node;
    int i = 0;
    while(i < data.size()){
        if(data[i] == ','){
            break;
        }
        node += data[i];
        ++i;
    }

    auto* res = new TreeNode(stoi(node));
    node = "";
    queue<TreeNode*> q;
    q.push(res);
    ++i;
    while(!q.empty()){
        TreeNode* curNode = q.front();
        q.pop();
        while(i<data.size()){
            if(data[i] == ','){
                if(node != "$"){
                    curNode->left = new TreeNode(stoi(node));
                }
                node = "";
                ++i;
                break;
            }
            node += data[i];
            ++i;
        }
        while(i<data.size()){
            if(data[i] == ','){
                if(node != "$"){
                    curNode->right = new TreeNode(stoi(node));
                }
                node = "";
                ++i;
                break;
            }
            node += data[i];
            ++i;
        }
        if(curNode->left){
            q.push(curNode->left);
        }
        if(curNode->right){
            q.push(curNode->right);
        }
    }
    return res;
}

/**
 * 注意，存在左右子树时，取左右子树最大的深度
 */
class Solution {
public:
    int TreeDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int level=1;
        if(!root->left && !root->right) return level;
        if(!root->left) return level + TreeDepth(root->right);
        if(!root->right) return level + TreeDepth(root->left);
        return level+max(TreeDepth(root->left), TreeDepth(root->right));
    }
};

class Solution1 {
public:
    int TreeDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int nLeft = TreeDepth(root->left);
        int nRight = TreeDepth(root->right);

        return (nLeft > nRight) ? (nLeft+1) : (nRight+1);

    }
};
// TODO：

int main(){
    string trees = "1,2,3,4,5,$,6,$,$,7,$,$,$";
    TreeNode* root = Deserialize(trees);

    cout<<Solution1().TreeDepth(root)<<endl;
    return 0;
}