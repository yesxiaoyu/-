#include <bits/stdc++.h>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

RandomListNode* CreateList(vector<int> a){

    if(a.size() == 0) return nullptr;
    RandomListNode* head = new RandomListNode(a[0]);
    RandomListNode* curNode = head;
    for(int i = 1; i < a.size(); i++){
        curNode->next = new RandomListNode(a[i]);
        curNode = curNode->next;
    }
    return head;
}

void PrintList(RandomListNode* head){

    if(head == nullptr) return;
    RandomListNode* curNode = head;
    while(curNode != nullptr){
        cout<<curNode->label<<" -> ";
        curNode = curNode->next;
    }
    cout<<"NULL"<<endl;
}

void DeleteList(RandomListNode* head){

    RandomListNode* curNode = head;
    while(curNode != nullptr){
        RandomListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
    return;
}

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead) return nullptr;
        nodeClone(pHead);
        connectRandom(pHead);
        return reconnect(pHead);
    }

private:
    //[1]复制结点，插入到原结点后方
    void nodeClone(RandomListNode *head)
    {
        RandomListNode *pNode = head;
        while (pNode != nullptr)
        {
            RandomListNode *pClone = new RandomListNode(pNode->label);
            pClone->next = pNode->next;
            pNode->next = pClone;
            pNode = pClone->next;
        }
    }

    //[2]还原新结点的random指针
    void connectRandom(RandomListNode *head)
    {
        RandomListNode *pNode = head;

        while (pNode != nullptr)
        {
            RandomListNode *pClone = pNode->next;
            if (pNode->random)
            {
                pClone->random = pNode->random->next;
            }
            pNode = pClone->next;
        }
    }

    //[3]拆分
    RandomListNode *reconnect(RandomListNode *head)
    {
        RandomListNode *pNode = head;
        RandomListNode *result = head->next;
        while (pNode != nullptr)
        {
            RandomListNode *pClone = pNode->next;
            pNode->next = pClone->next;
            pNode = pNode->next;
            if (pNode != nullptr)
                pClone->next = pNode->next;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<int> a = {1, 2, 3, 4, 5};
    RandomListNode* head = CreateList(a);
    RandomListNode* clone = Solution().Clone(head);
    PrintList(head);
    PrintList(clone);
    DeleteList(head);
    DeleteList(clone);
    return 0;
}
