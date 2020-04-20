// Author : lihongyu
// Time   : 2019-12-10

#include<bits/stdc++.h>
using namespace std;

// 剑指offer-52 两个链表的第一个公共节点
// 思路：从后向前思考，首先计算两个链表长度，保证第二个链表长于第一个链表，然后从后向前找公共节点.
// 与二叉树的最低公共祖先类似.
// 时间复杂度: O(m+n)
// 空间复杂度: O(1)


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
        val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        int len1 = getListLen(pHead1);
        int len2 = getListLen(pHead2);

        if (len1 > len2) {
            swap(pHead1, pHead2);
            swap(len1, len2);
        }
        int lenDiff = len2 - len1;
        for (int i = 0; i < lenDiff; ++i)   pHead2 = pHead2->next;
        while ((pHead1 != nullptr) && (pHead2 != nullptr) && (pHead1->val != pHead2->val)){
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
    }

private:
    int getListLen(ListNode *pHead) {
        int resLen = 0;
        ListNode* pNode = pHead;
        while (pNode != nullptr) {
            resLen++;
            pNode = pNode->next;
        }

        return resLen;
    }
};


ListNode* CreateList(vector<int> a){

    if(a.empty())  return nullptr;

    auto* head = new ListNode(a[0]);
    ListNode* curNode = head;
    for(int i = 1; i <= a.size(); i++){
        curNode->next = new ListNode(a[i]);
        curNode = curNode->next;
    }
    return head;
}

void PrintList(ListNode* head){

    ListNode* curNode = head;
    while(curNode->next != nullptr){
        cout<<curNode->val<<" -> ";
        curNode = curNode->next;
    }
    cout<<"NULL"<<endl;
}

void DestroyList(ListNode* head){

    ListNode* curNode = head;
    while(curNode->next != nullptr){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
}

// TODO：P254借助栈的思路值得尝试，不过空间复杂度较差
// 时间复杂度: O(m+n)
// 空间复杂度: O(m+n)

int main(){
    vector<int> l1 = {1, 2, 3, 6, 7};
    vector<int> l2 = {4, 5, 6, 7};
    ListNode* head1 = CreateList(l1);
    ListNode* head2 = CreateList(l2);
    cout<<Solution().FindFirstCommonNode(head1, head2)->val<<endl;
    DestroyList(head1);
    DestroyList(head2);
    return 0;
}