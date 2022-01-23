#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {} 
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n){
            int size=1;
            ListNode* temp = head;

            while(temp->next!=NULL)
            {
                temp=temp->next;
                size++;
            }

            int loc=size-n;
            int i=1;
            temp=head;

            while(i<loc)
            {
                temp=temp->next;
                i++;
            }

            if(loc==0)
            {
                head=temp->next;
                temp->next=NULL;
            }

            else
            {
                if(temp->next==NULL)
                {
                    return NULL;
                }

                else
                {
                    if(temp->next->next==NULL)
                    {
                        temp->next=NULL;
                    }

                    else
                    {
                        temp->next=temp->next->next;
                    }
                }
            }

            return head;
        }
};