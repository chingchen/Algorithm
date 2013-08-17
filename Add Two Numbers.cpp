/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int carry = 0;
        ListNode* pre ,* current ,*start;
        start = pre = current = ( l2 == NULL ? l1:l2);
        while(l1 != NULL || l2 != NULL || carry > 0)
        {
            int value1 , value2;
            if(l1 == NULL )
                value1 = 0;
            else
            {
                value1= l1->val ;
                current = l1;
            }
                
            if(l2 == NULL)
                value2 = 0;
            else
            {
                value2 = l2->val;
                current = l2;
                
            }
            
            if( current == NULL && carry >0 )
            {
                current = new ListNode(carry);
            }
            else if( current == NULL )
               break;
               
            if( value1 + value2 + carry > 9)
            {
                current ->val = value1 + value2 + carry -10;
                carry = 1;
            }
            else
            {
                current ->val = value1 + value2 + carry;
                carry = 0;
            }           
            
            if(l1 != NULL)
               l1 = l1->next;
            if(l2 !=  NULL)
              l2 = l2->next;

			if( pre != current)
			{
				pre ->next = current;
				pre = current;
			}
            current = NULL;
        }
        return start;
    }
};