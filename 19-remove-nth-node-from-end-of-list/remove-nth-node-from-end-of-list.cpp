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
   ListNode* removeNthFromEnd(ListNode* head, int n) {

    int cnt=0;
    ListNode* temp=head;

    while(temp !=nullptr){
        temp=temp->next;
        cnt++;
    }

    if(cnt == n){
            return head->next;
        }

        // Second pass to reach (cnt-n)th node
        int pos = cnt - n;
        ListNode* prev = head;
        for(int i=1; i<pos; i++){
            prev = prev->next;
        }

        // Delete the node
        prev->next = prev->next->next;

        return head;
   }
};