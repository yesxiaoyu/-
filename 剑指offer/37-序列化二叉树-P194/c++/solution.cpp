#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){};
};

//使用先序遍历和中序遍历，或中序遍历和后序遍历确定二叉树存在两个缺点：
//1、要求二叉树中不能有数值重复的两个节点
//2、只有当两个序列中所有数据都读出后才能反序列化
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

//vector<string> res;
//vector<string> Serilize(TreeNode* tree){
//
//    if (tree == nullptr){
//        res.emplace_back("#");
//        return res;
//    }
//
//    res.emplace_back(to_string(tree->val));
//    Serilize(tree->left);
//    Serilize(tree->right);
//
//    return res;
//}

//void printVec(vector<string> v){
//    for (int i = 0; i < v.size(); ++i) {
//        cout<<v[i]<<"";
//    }
//    cout<<endl;
//}

//TODO:还未想出来解决方案
//TreeNode* Deserialize(vector<string> s){
//    if (s.size() == 0 || s[0] == "$")   return nullptr;
//    TreeNode* root = new TreeNode(stoi(s[0]));
//    s.pop_back();
//    root->left = Deserialize(s);
//    root->right = Deserialize(s);
//    return root;
//}

// leetcode-449

// Encodes a tree to a single string.
string Serialize(TreeNode* root) {
    string res;
    if(!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(!node){
            res += "$,";
        }else{
            res += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
    }
    return res;
}

// Decodes your encoded data to tree.
TreeNode* Deserialize(string data) {
    if(data.empty()){return NULL;}
    string node;
    int i = 0;
    while(i < data.size()){
        if(data[i] == ','){
            break;
        }
        node += data[i];
        ++i;
    }

    TreeNode* res = new TreeNode(stoi(node));
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
int main(int argc, char* argv[])
{
    vector<int> pre = {1, 2, 4, 3, 5, 6}, vin = {4, 2, 1, 5, 3, 6};

    TreeNode* tree = reConstructBinaryTree(pre, vin);
    postOrder(tree);
    cout<<endl;
    string rst = Serialize(tree);
    cout<<rst<<endl;

    TreeNode* retree = Deserialize(rst);
    postOrder(retree);
    cout<<endl;
    return 0;
}