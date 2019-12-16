// Author : lihongyu
// Time   : 2019-12-15

#include<bits/stdc++.h>
using namespace std;

// leetcode-337 打家劫舍（树型）

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 思路：
/// Brute Force
/// Time Complexity: O(2^n), where n is the nodes' number in the tree
/// Space Complexity: O(h), where h is the tree's height
class Solution {

private:
    map<pair<TreeNode*, int>, int> dp;

public:
    int rob(TreeNode* root) {

        dp.clear();
        return rob(root, true);
    }

private:
    int rob(TreeNode* root, bool include){

        if(root == NULL)
            return 0;

        pair<TreeNode*, int> p = make_pair(root, include);
        if(dp.find(p) != dp.end())
            return dp[p];

        int res = rob(root->left, true) + rob(root->right, true);
        if(include)
            res = max(root->val + rob(root->left, false) + rob(root->right, false),
                       res);

        return dp[p] = res;
    }
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

/// Memory Search
/// Time Complexity: O(n), where n is the nodes' number in the tree
/// Space Complexity: O(n)
class Solution2 {

public:
    int rob(TreeNode* root) {
        return rob(root, true);
    }

private:
    int rob(TreeNode* root, bool include){

        if(root == NULL)
            return 0;

        int res = rob(root->left, true) + rob(root->right, true);
        if(include)
            res = max(root->val + rob(root->left, false) + rob(root->right, false),
                      res);

        return res;
    }
};

/// Redefine the recursive function and return a two-element array
/// represent the include and exclude maximum result for robbing the node
///
/// Time Complexity: O(n), where n is the nodes' number in the tree
/// Space Complexity: O(1)
class Solution3 {

public:
    int rob(TreeNode* root) {
        vector<int> result = tryRob(root);
        return max(result[0], result[1]);
    }

private:
    vector<int> tryRob(TreeNode* root){

        if(root == NULL)
            return vector<int>(2, 0);

        vector<int> resultL = tryRob(root->left);
        vector<int> resultR = tryRob(root->right);
        vector<int> res(2, 0);

        res[0] = resultL[1] + resultR[1];
        res[1] = max(res[0], root->val + resultL[0] + resultR[0]);

        return res;
    }
};

// TODO："3,2,3,$,3,$,1" output is 6 where should be 7.

int main(){

    string s = "3,4,5,1,3,$,1";
    TreeNode* root = Deserialize(s);
    cout<<Solution3().rob(root)<<endl;

    return 0;
}