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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k= lists.size();
        vector<int> extra;

        for(int i=0; i<k; i++){
            ListNode* temp2=lists[i];
            while(temp2){
                extra.push_back(temp2->val);
                temp2=temp2->next;
            }
        }

        sort(extra.begin(), extra.end());

        ListNode* ans= new ListNode (0,nullptr);
        ListNode* t=ans;
        

        for(int x : extra){
            t->next= new ListNode(x);
            t=t->next;
        }
        return ans->next;
    }
};
