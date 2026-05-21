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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* small=NULL;
        ListNode* smallhead=NULL;
        ListNode* large=NULL;
        ListNode* largehead=NULL;
        while(head!=NULL){
            ListNode* temp=new ListNode(head->val);
            if(head->val<x){
                if(small){
                    small->next=temp;                    
                    small=small->next;
                }
                else{
                    small=temp;
                    smallhead=temp;
                }
            }
            else{
                if(large){
                    large->next=temp;                    
                    large=large->next;
                }
                else{
                    large=temp;
                    largehead=temp;
                }
            }

            head=head->next;
        }
        if(!small){
            return largehead;
        }
        small->next=largehead;
        return smallhead;
    }
};