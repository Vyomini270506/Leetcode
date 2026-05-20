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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            s.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
            
        }
        if(fast!=NULL && fast->next==NULL){
            slow=slow->next;
        }
        while(slow!=NULL){
            int x=s.top();
            s.pop();
            if(slow->val!=x){
                return false;
            }
            slow=slow->next;
        }
        return true;
    }
};