package com.company;

import java.util.ArrayList;
import java.util.List;

class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
}
class Solution {
    public List<List<Integer>> resultList=null;
    public List<List<Integer>> levelOrder(TreeNode root) {
        resultList=new ArrayList<List<Integer>>();
        helper(root,0);
        return resultList;
    }

    public void helper(TreeNode node ,int level){
        if(node==null) return;
        if(resultList.size()<=level){
            resultList.add(new ArrayList<Integer>());
        }
        resultList.get(level).add(node.val);
        helper(node.left,level+1);
        helper(node.right,level+1);
    }
}

public class Main {

    public static void main(String[] args) {
	    int[] arr = {1,8,6,2,5,4,8,3,7};
	    System.out.println(new Solution().levelOrder(arr)); // 49
    }
}
