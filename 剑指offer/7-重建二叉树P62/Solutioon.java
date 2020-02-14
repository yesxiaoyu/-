// Author : lihongyu
// Time   : 2020-2-14
// leetcode-面试题07. 重建二叉树
// 思路：二叉树
// 时间复杂度: O(n)
// 空间复杂度: O(1)

import java.util.Dictionary;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {

        if (preorder == null || inorder == null || inorder.length == 0 || preorder.length != inorder.length) {
            return null;
        }
        return help(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);

    }
    private TreeNode help(int[] preorder, int pStart, int pEnd, int[] inorder, int iStart, int iEnd) {
        //递归的第一步：递归终止条件，避免死循环
        if (pStart > pEnd || iStart > iEnd) {
            return null;
        }
        //重建根节点
        TreeNode treeNode = new TreeNode(preorder[pStart]);
        int index = 0;  //index找到根节点在中序遍历的位置
        while (inorder[iStart + index] != preorder[pStart]) {
            index++;
        }
        //重建左子树
        treeNode.left = help(preorder, pStart + 1, pStart + index, inorder, iStart, iStart + index - 1);
        //重建右子树
        treeNode.right = help(preorder, pStart + index + 1, pEnd, inorder, iStart + index + 1, iEnd);
        return treeNode;

    }

    private void postOrder(TreeNode root){
    	if(root == null)	return;
    	postOrder(root.left);
    	postOrder(root.right);
    	System.out.print(root.val + " ");
	}

    public static void printArray(int[] nums){
        for(Integer e: nums)
            System.out.print(e + " ");
        System.out.println();
    }

    public static void main(String[] args) {

        int[] preorder = {3, 9, 20, 15, 7};
        int[] inorder = {9, 3, 15, 20, 7};

        TreeNode root = (new Solution()).buildTree(preorder, inorder);
        (new Solution()).postOrder(root);
//        printArray(res);

    }
}


// TODO: