// Problem link: https://leetcode.com/problems/palindrome-linked-list/description/

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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1, find the midpoint (tortoise and hare algorithm)
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2, reverse the second half of the linked list
        ListNode* previous = NULL;
        while(slow)
        {
            ListNode* tmpNode = slow->next;
            slow->next = previous;
            previous = slow;
            slow = tmpNode;
        }

        // Step 3, traverse the first half of the list and the second, reversed half of the list at the same time
        // Compare values to see if this linked list is a palindrome
        ListNode* first = head;
        ListNode* second = previous;
        
        while(second)
        {
            if(first->val != second->val)
            {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;  
    }
};
