// Author : lihongyu
// Time   : 2019-12-12

#include<bits/stdc++.h>
using namespace std;

// 剑指offer-55 判断一颗二叉树是否为平衡二叉树
// 思路：树中每个节点左右子树深度相差不超过1，该树即为平衡二叉树
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
    bool IsBalanced_Solution(TreeNode* root) {
        if(root==nullptr) return true;
        int left = TreeDepth(root->left);
        int right = TreeDepth(root->right);
        if (abs(left - right) > 1) return false;
        return IsBalanced_Solution(root->left) && IsBalanced_Solution(root->right);
    }
private:
    int TreeDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int nLeft = TreeDepth(root->left);
        int nRight = TreeDepth(root->right);

        return (nLeft > nRight) ? (nLeft+1) : (nRight+1);
    }
};

/**
 * 方法1中每个节点会被遍历多次，采用后序遍历进行优化
 * 从下往上遍历，如果子树是平衡二叉树，则返回子树的高度；
 * 如果发现子树不是平衡二叉树，则直接停止遍历，这样至多只对每个结点访问一次。
 * 代码中没搞懂优化在哪...
 */
class Solution1 {
public:
    bool IsBalanced_Solution(TreeNode* root) {
        return getDepth(root) != -1;
    }
private:
    int getDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        int left = getDepth(root->left);
        if (left == -1) return -1;
        int right = getDepth(root->right);
        if (right == -1) return -1;
        return abs(left - right) > 1 ? -1 : 1 + max(left, right);
    }
};
// TODO：

int main(){
    string trees = "1,2,3,4,5,$,6,$,$,7,$,$,$";
    TreeNode* root = Deserialize(trees);

    cout<<Solution1().IsBalanced_Solution(root)<<endl;
    return 0;
}