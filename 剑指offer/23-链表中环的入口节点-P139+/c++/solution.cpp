// Author : lihongyu
// Time   : 2019-12-26

#include<bits/stdc++.h>
using namespace std;

// 剑指offer 23-链表中环的入口节点-P139
// 思路：
// 时间复杂度: O(n)
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
         if(pHead==NULL)return NULL;
         //先计算环中结点的个数
         //快慢指针相遇结点一定在环中
         ListNode *pFast=pHead,*pSlow=pHead->next;
         while(pFast!=NULL&&pSlow!=NULL&&pFast!=pSlow){
            pSlow=pSlow->next;
            pFast=pFast->next;
            if(pFast!=NULL)
                pFast=pFast->next;
         }
         //开始统计环结点数
         int countNum=1;
         ListNode *pTempNode=pFast->next;
         if(pFast==pSlow&&pFast!=NULL){
             while(pTempNode!=pFast){
                 pTempNode=pTempNode->next;
                 ++countNum;
             }
         }
         else
             return NULL;
         //再设两指针，一先一后
         ListNode *pNode1=pHead,*pNode2=pHead;
         for(int i=0;i<countNum;i++){
                pNode1=pNode1->next;
         }
         while(pNode1!=pNode2){
             pNode1=pNode1->next;
             pNode2=pNode2->next;
         }
         return pNode1;

    }
};

// TODO:
int main(){

    return 0;
}