class Solution {
public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        priority_queue<ListNode*,vector<ListNode*>,Solution> pq;
        while(head!=NULL){
            pq.push(head);
            head=head->next;
        }
        ListNode* newHead=pq.top();
        pq.pop();
        ListNode* temp=newHead;
        while(!pq.empty()){
            temp->next=pq.top();
            temp=temp->next;
            pq.pop();
        }
        temp->next=NULL;
        return newHead;
    }
};