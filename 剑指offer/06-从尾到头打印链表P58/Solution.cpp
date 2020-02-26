// Author : lihongyu
// Time   : 2019-10-28

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* CreateList(int a[], int n){
	
	if(n == 0)	return NULL;
	
	ListNode* head = new ListNode(a[0]);
	ListNode* curNode = head;
	
	for(int i = 1; i < n; i++){
		curNode->next = new ListNode(a[i]);
		curNode = curNode->next;
	}
	return head;
}

void PrintList(ListNode* head){
	
	ListNode* curNode = head;
	while(curNode != NULL){
		cout<<curNode->val<<" -> ";
		curNode = curNode->next;
	}
	cout<<"NULL"<<endl;
	return;
}

void DeleteList(ListNode* head){
	
	ListNode* curNode = head;
	while(curNode != NULL){
		ListNode* delNode = curNode;
		curNode = curNode->next;
		delete delNode;
	}
	
	return;
}
//reverse list via stack
void IterativePrintListReverse(ListNode* head){
	
	stack<ListNode*> nodes;
	
	ListNode* curNode = head;
	while(curNode != NULL){
		
		nodes.push(curNode);
		curNode = curNode->next;
	}
	while(!nodes.empty()){
		curNode = nodes.top();
		cout<<curNode->val<<" -> ";
		nodes.pop();
	}
	cout<<"NULL"<<endl;
	return;
}

void RecursivePrintListReverse(ListNode* head){
	
	if(head != NULL){
		if(head->next != NULL){
			RecursivePrintListReverse(head->next);
		}
		cout<<head->val<<" -> ";
	}
	return;
} 

//leetcode-206
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
		ListNode* cur = head;
		while(cur != NULL){
			ListNode* next = cur->next;
			
			cur->next = pre;
			pre = cur;
			cur = next;
		} 
		return pre;
    }
};

int main(){
	
	int a[] = {1, 2, 3, 4, 5};
	
	ListNode* head = CreateList(a, 5);
	PrintList(head);
	
//	ListNode* h2 = Solution().reverseList(head);
//	PrintList(h2);
	
//	IterativePrintListReverse(head);

	RecursivePrintListReverse(head);
	cout<<"NULL"<<endl;
	
//	DeleteList(h2);
	return 0;
} 