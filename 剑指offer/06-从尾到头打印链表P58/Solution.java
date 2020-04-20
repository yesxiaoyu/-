// Author : lihongyu
// Time   : 2020-2-14
// leetcode-面试题06. 从尾到头打印链表
// 思路：链表
// 时间复杂度: O(n)
// 空间复杂度: O(1)

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode CreateList(int[] a){
        int n = a.length;
        if(n == 0)	return null;

        ListNode head = new ListNode(a[0]);
        ListNode curNode = head;

        for(int i = 1; i < n; i++){
            curNode.next = new ListNode(a[i]);
            curNode = curNode.next;
        }
        return head;
    }

    public int[] reversePrint(ListNode head) {

        int i = 0, j = 0;
        ListNode pre = null;
		ListNode cur = head;
		while(cur != null){
			ListNode next = cur.next;
			cur.next = pre;
			pre = cur;
			cur = next;
			i++;
		}
		int[] res = new int[i];
		while(pre != null){
            res[j++] = pre.val;
            pre = pre.next;
        }
		return res;
    }

    public static void printArray(int[] nums){
        for(Integer e: nums)
            System.out.print(e + " ");
        System.out.println();
    }

    public static void main(String[] args) {

        int[] a = {1, 3, 2};
        ListNode head = (new Solution()).CreateList(a);
        int[] res = (new Solution()).reversePrint(head);
        printArray(res);

    }
}


// TODO: