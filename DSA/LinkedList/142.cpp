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
    ListNode *detectCycle(ListNode *head) {


        //in this problem we have to find the starting node of cycle we use here slow and fast pointer
        // if slow == fats the reset the slow to head as it is not neccesary that our slow meet fast at the starting point  
        // the loopagain till slow == fast
        // and new meeting point will be our ans
        
        ListNode*fast = head;
        ListNode*slow = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};