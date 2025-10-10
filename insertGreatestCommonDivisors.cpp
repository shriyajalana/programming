/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class Solution {
    public:
        ListNode* insertGreatestCommonDivisors(ListNode* head) {
            if(head==NULL || head->next==NULL) return head;
            ListNode* current=head;
            ListNode* next=head->next;
            while(next!=NULL){
                ListNode* node=new ListNode(gcd(current->val, next->val));
                current->next=node;
                node->next=next;
                current=next;
                next=current->next;
            }
            return head;
        }
    };