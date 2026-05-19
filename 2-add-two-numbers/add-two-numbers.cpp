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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        bool flag=true;
        ListNode* start=new ListNode();        
        ListNode* ans=new ListNode();
        while(l1!=NULL && l2!=NULL){
            int x=l1->val+l2->val+c;
            int y=x%10;
            c=x/10;
            if(flag){
                start=new ListNode(y);
                ans=start;
                flag=false;
            }
            else{
                ans->next=new ListNode(y);
                ans=ans->next;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int y=l1->val+c;
            int x=y%10;
            c=y/10;
            ans->next=new ListNode(x);
            ans=ans->next;
            l1=l1->next;
        }
        while(l2!=NULL){
            int y=l2->val+c;
            int x=y%10;
            c=y/10;
            ans->next=new ListNode(x);
            ans=ans->next;
            l2=l2->next;
        }
        if(c>0){
            ans->next=new ListNode(c);
            ans=ans->next;
        }
        return start;
    }
};