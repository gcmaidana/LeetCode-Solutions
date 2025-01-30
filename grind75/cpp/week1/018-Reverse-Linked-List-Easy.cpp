// Problem link: https://leetcode.com/problems/reverse-linked-list/

// Iterative
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
        
    }
};

// Recursive

class Solution {
public:

    ListNode* rec(ListNode* prev, ListNode* curr)
    {
        if(curr == NULL)
        {
            return prev;
        }
        else
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            return rec(curr, nextNode);
        }

    }

    ListNode* reverseList(ListNode* head) {

        return rec(NULL, head);
        
    }
};
