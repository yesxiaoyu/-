#include<bits/stdc++.h>
using namespace std;

// 203. 移除链表元素
// https://leetcode-cn.com/problems/remove-linked-list-elements/submissions/
// 时间复杂度: O(n)
// 空间复杂度: O(1)


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

// 分别考虑删除头结点和中间元素
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        while(head != nullptr && head->val == val){
            ListNode* del = head;
            head = head->next;
            del->next = nullptr;
        }
        if(head == nullptr) return nullptr;
        ListNode* pre = head;
        while(pre->next != nullptr){
            if(pre->next->val == val){
                ListNode* del = pre->next;
                pre->next = del->next;
                del->next = nullptr;
            }
            else    pre = pre->next;
        }
        return head;
    }
};

// 分别考虑删除头结点和中间元素，简化写法
class Solution2 {
public:
    ListNode* removeElements(ListNode* head, int val) {

        while(head != nullptr && head->val == val)   head = head->next;
        if(head == nullptr) return nullptr;
        ListNode* pre = head;
        while(pre->next != nullptr){
            if(pre->next->val == val)   pre->next = pre->next->next;
            else    pre = pre->next;
        }
        return head;
    }
};

// 使用虚拟头结点
class Solution3 {
public:
    ListNode* removeElements(ListNode* head, int val) {

        auto* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        while(pre->next != nullptr){
            if(pre->next->val == val)   pre->next = pre->next->next;
            else    pre = pre->next;
        }
        return dummyHead->next;
    }
};

// 使用递归方式
class Solution4 {
public:
    ListNode* removeElements(ListNode* head, int val) {

        if (head == nullptr) return nullptr;
        ListNode* res = removeElements(head->next, val);
        if (head->val == val) return res;
        else{
            head->next = res;
            return head;
        }
    }
};

// 使用递归方式，精简版
class Solution5 {
public:
    ListNode* removeElements(ListNode* head, int val) {

        if (head == nullptr) return nullptr;
        head->next = removeElements(head->next, val);
//        if (head->val == val) return head->next;
//        else return head;
        return head->val == val ? head->next : head;
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

int main() {

    vector<int> arr = {1, 2, 6, 3, 4, 5, 6};
    ListNode* head = CreateList(arr);
    PrintList(head);

    ListNode* res_head = Solution5().removeElements(head, 6);
    PrintList(res_head);

    DestroyList(res_head);

    return 0;
}