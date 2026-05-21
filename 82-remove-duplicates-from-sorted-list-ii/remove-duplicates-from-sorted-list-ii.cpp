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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        set<int> l;
        ListNode* temp=head->next;
        int prev=head->val;
        while(temp!=NULL){
            if(temp->val==prev){
                l.insert(prev);
            }
            prev=temp->val;
            temp=temp->next;
        }
        temp=head;
        ListNode* pre=NULL;
        while(temp!=NULL){
            if(l.find(temp->val)!=l.end()){
                if(!pre){
                    pre=temp;
                }
                else{
                    
                pre->next=temp->next;
                }
            }
            else{
                if(!pre){
                    pre=head;
                }
                else{
                    
                pre=pre->next;
                }
            }
            temp=temp->next;
        }
        if(l.find(head->val)!=l.end()){
            head=head->next;
        }
        return head;
    }
};