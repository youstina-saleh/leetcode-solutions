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
        //the dummy is to avoid losing the address of the list, we will return its next by the way.
        ListNode* dummy = new ListNode(-1); 
        ListNode* current = dummy;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int leftover = 0;
    
        while(temp1 || temp2){
            int sum = leftover;
            if(temp1) 
                sum += temp1->val;
            if(temp2)
                sum += temp2->val;

            ListNode* newNode = new ListNode(sum%10);

            leftover = sum /10;

            current->next = newNode;
            current = current->next;

            if(temp1) //to avoid trying to access illegal address.
                temp1 = temp1->next;
            if(temp2)
                temp2 = temp2->next;
        }
        if(leftover){ //not zero and we do still have a number
            ListNode* newNode = new ListNode(leftover);
            current->next = newNode;
            current = current->next;
        }

    return dummy->next;
    }
};