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

    if(vin.empty()){
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) return nullptr;
        TreeNode* pre = nullptr;

        convertHelper(pRootOfTree, pre);

        TreeNode* res = pRootOfTree;
        while(res ->left)
            res = res ->left;
        return res;
    }

private:
    // 中序遍历
    void convertHelper(TreeNode* cur, TreeNode*& pre) {
        if (cur == nullptr) return;

        convertHelper(cur->left, pre);

        cur->left = pre;
        if (pre) pre->right = cur;
        pre = cur;

        convertHelper(cur->right, pre);
    }
};

void PrintList(TreeNode* head){

    if(head == nullptr) return;
    TreeNode* curNode = head;
    while(curNode != nullptr){
        cout<<curNode->val<<" -> ";
        curNode = curNode->right;
    }
    cout<<"NULL"<<endl;
}

int main(int argc, char* argv[])
{
    vector<int> pre = {10, 6, 4, 8, 14, 12, 16}, vin = {4, 6, 8, 10, 12, 14, 16};

    TreeNode* tree = reConstructBinaryTree(pre, vin);
    postOrder(tree);
    cout<<endl;

    TreeNode* list = Solution().Convert(tree);
    PrintList(list);

    return 0;
}
