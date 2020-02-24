// Author : lihongyu
// Time   : 2020-2-24
// 面试题18. 删除链表的节点
// 思路：链表
// 时间复杂度: O(n)
// 空间复杂度: O(n)
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        if(head == null)return null;
        ListNode cur = head;
        ListNode pre = null;
        // 头节点的元素值与要删除的值相等
        if(head.val == val)return head.next;
        // 找到要删除节点的前驱节点
        while(cur != null && (cur.val != val)){
            pre = cur;
            cur = cur.next;
        }
        // 最后节点为空
        if(cur.next == null){
            pre.next = null;
        }else{
            pre.next = cur.next;
        }
        return head;
    }
}

// TODO: