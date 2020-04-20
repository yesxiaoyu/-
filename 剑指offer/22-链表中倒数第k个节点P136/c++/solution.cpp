// Author : lihongyu
// Time   : 2019-11-07

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):    val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* CreateList(vector<int> a){

        if(a.size() == 0) return nullptr;
        ListNode* head = new ListNode(a[0]);
        ListNode* curNode = head;
        for(int i = 1; i < a.size(); i++){
            curNode->next = new ListNode(a[i]);
            curNode = curNode->next;
        }
        return head;
    }

    void PrintList(ListNode* head){

        if(head == nullptr) return;
        ListNode* curNode = head;
        while(curNode != nullptr){
            cout<<curNode->val<<" -> ";
            curNode = curNode->next;
        }
        cout<<"NULL"<<endl;
    }

    ListNode* FindKthToTail(ListNode* head, unsigned int k) {

        if(head == nullptr || k==0) return nullptr;
        ListNode* m = head;
        ListNode* n = head;
        for(int i = 0; i < k-1; i++){
            if(m->next != nullptr)
                m = m->next;
            else
                return nullptr;
        }
        while(m->next != nullptr){
            m = m->next;
            n = n->next;
        }
        return n;
    }


};

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6};
    ListNode* head = Solution().CreateList(a);
    Solution().PrintList(head);
    ListNode* ktail = Solution().FindKthToTail(head, 3);
    cout<<ktail->val<<endl;
    return 0;
}