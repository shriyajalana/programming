class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
            if(head==NULL || k==1){
                    return head;
            }
            ListNode* dummy=new ListNode(0);
            dummy->next=head;
            ListNode* current=dummy;
            ListNode* Next=dummy;
            ListNode* prev=dummy;
            int count=0;
            while(current->next!=NULL){
                    current=current->next;
                    count++;
            }
            cout<<count<<" ";
            while(count>=k){
                    current=prev->next;
                    Next=current->next;
                    for(int i=1;i<k;i++){
                            current->next=Next->next;
                            Next->next=prev->next;
                            prev->next=Next;
                            Next=current->next;    
                    }
                    prev=current;
                    count=count-k;
            }
            return dummy->next;        
    }
};
