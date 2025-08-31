/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* x=headA;
    
        map<ListNode*,int> mpp; 
        
        while(x != NULL){
            mpp[x]=1;
            x=x->next;
        }

       ListNode* y=headB;

        while(y !=NULL){
            if(mpp.find(y) != mpp.end()){
                return y;
            }

            else{
                y=y->next;
            }

        }

        return NULL;


        
        
    }
};