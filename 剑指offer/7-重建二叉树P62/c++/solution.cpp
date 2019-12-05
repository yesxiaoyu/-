// Author : lihongyu
// Time   : 2019-10-29

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *next;
	TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/*
         1
        / \
       2   3 
      /   / \
     4   5   6
      \     /
       7   8
*/

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        vector<int> left_pre, right_pre, left_vin, right_vin;
        
        if(vin.size() == 0){
        	return NULL;
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
    	
    	if(root == NULL)	return;
    	postOrder(root->left);
    	postOrder(root->right);
    	cout<<root->val<<endl;
	}
	
	int maxDepth(TreeNode* root){
		if(root == NULL)	return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
	
	void _hiOrder(TreeNode* root, int depth){
    	
    	if(root == NULL)	return;
    	if(depth == 1){
    		cout<<root->val<<endl;
    		return;
		}
    	_hiOrder(root->left, depth-1);
    	_hiOrder(root->right, depth-1);
	}
	
	void hiOrder(TreeNode* root, int depth){
		
		if(root == NULL || depth == 0)	return;
		for(int i = 1; i <= depth; i++){
			_hiOrder(root, i);
		}
	}
	
//	遇到叶子节点不递归，否则接着往子树递归，每次递归层数加1
	int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int level=1;
        if(!root->left&&!root->right) return level;
        if(!root->left) return level+minDepth(root->right);
        if(!root->right) return level+minDepth(root->left);
        return level+min(minDepth(root->left),minDepth(root->right));
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)	return NULL;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
    
    int fun(struct TreeNode* l_root, struct TreeNode* r_root){
        if (l_root == NULL && r_root == NULL) return true;
        if (l_root == NULL || r_root == NULL) return false;

        return    (l_root->val == r_root->val)   &&
               fun(l_root->left,  r_root->right) &&
               fun(l_root->right, r_root->left);
    }
        
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return fun(root->left, root->right);
    }
    
    TreeNode* GetNext(TreeNode* node){
    	if(node == NULL)	return NULL;
    	TreeNode* resNode = NULL;
    	if(node->right != NULL){
    		TreeNode* rNode = node->right;
    		while(rNode->left != NULL){
    			rNode = rNode->left;
			}
			resNode = rNode;
		}else if(node->next != NULL){
			TreeNode* curNode = node;
			TreeNode* pNode = node->next;
			while(pNode != NULL && curNode == pNode->right){
				curNode = pNode;
				pNode = pNode->next;
			}
			resNode = pNode;
		}
		
		return resNode;
	} 
	
	vector<string> binaryTreePaths(TreeNode* root) {
		
        vector<string> res;
        if(root == NULL)	return res;
        if(root->left == NULL && root->right == NULL){
        	res.push_back(to_string(root->val));
		}
		vector<string> lp = binaryTreePaths(root->left);
		for(int i = 0; i < lp.size(); i++){
			res.push_back(to_string(root->val) + "->" + lp[i]);
		}
		vector<string> rp = binaryTreePaths(root->right);
		for(int i = 0; i < rp.size(); i++){
			res.push_back(to_string(root->val) + "->" + rp[i]);
		}
		return res;
    }
};

int main(){
	vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
	vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
	
	TreeNode* root = Solution().reConstructBinaryTree(pre, vin);
	Solution().postOrder(root);
	
	int max_depth = Solution().maxDepth(root);
	cout<<endl<<max_depth<<endl<<endl;
	
	Solution().hiOrder(root, max_depth);
	
	cout<<endl<<Solution().minDepth(root);
	
	TreeNode* root2 = Solution().invertTree(root);
	cout<<endl<<endl;
	
	Solution().hiOrder(root2, max_depth);
	cout<<endl<<endl;
	
	cout<<Solution().isSymmetric(root)<<endl<<endl;
	
	TreeNode* nroot = Solution().GetNext(root);
	cout<<nroot->val<<endl<<endl;
	
	vector<string> resPath = Solution().binaryTreePaths(root);
	for(int i = 0; i < resPath.size(); i++){
		cout<<resPath[i]<<endl;
	}
	return 0;
}