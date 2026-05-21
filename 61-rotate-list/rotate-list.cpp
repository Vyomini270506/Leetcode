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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k == 0){
            return head;
        }
        ListNode* l2=NULL;
        int i=1;
        temp=head;
        while(i<n-k){
            temp=temp->next;
            i++;
        }
        l2=temp->next;
        temp->next=NULL;
        ListNode* a=l2;
        while(a && a->next!=NULL){
            a=a->next;
        }
        a->next=head;
        return l2;

    }
};