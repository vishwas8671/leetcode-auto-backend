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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans={INT_MAX,INT_MIN};
        ListNode* prev=head;
        ListNode* curr=head->next;
        int pos=1,first=-1,last=-1;
        while(curr->next){
            if((curr->val>prev->val&&curr->val>curr->next->val)||(curr->val<prev->val&&curr->val<curr->next->val)){
                if(first==-1) first=pos;
                else ans[0]=min(ans[0],pos-last);
                last=pos;
                ans[1]=max(ans[1],pos-first);
            }
            prev=curr;
            curr=curr->next;
            pos++;
        }
        if(first==-1||first==last) return {-1,-1};
        return ans;
    }
};