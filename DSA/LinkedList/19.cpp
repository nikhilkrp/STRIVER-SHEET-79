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
        // here i have used the counting approach to find the postion which i have to be deleted so find size
        // of the LL and then i have reach the postion using an iterator and after that i have updated the link  
        ListNode*temp = head;
        int count = 0;


        while(temp!=NULL){
            count++;
            temp=temp->next;
        }

        if(count==n){
            ListNode*node = head;
            head = head->next;
            delete node;
            return head;
        }

        int position = count - n-1;
        int i = 0;
        ListNode*prev = head;
        while(i<position){
            prev = prev->next;
            i++;
        }
        prev->next = prev->next->next;
       return head;
        
    }
};