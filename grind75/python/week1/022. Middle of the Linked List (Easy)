# Question link: https://leetcode.com/problems/middle-of-the-linked-list/



# So basically, in order to find the midpoint, my original solution was to
# make a dummy node and iterate through the linked list and count up the number of nodes,
# then handle how to get the midpoint (2nd node in the middle for cases where there's an even node or
# just mid point for odd number of nodes), then iterate through the linkedlist and return the head
# Not the worst solution, but the problem with this original solution of mine is that I'm traversing the linked list
# twice


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:

        dummy = ListNode(0)
        tail = dummy

        tail.next = head
        tail = tail.next
        count = 0

        while tail:
            print(tail.val)
            tail = tail.next
            count +=1 
        print(count)

        iterate = 0
        if count % 2 == 0:
            iterate = (count / 2) + 1
        else:
            iterate = math.ceil(count / 2)
        iterate = int(iterate)

        
        for i in range(1, iterate):
            head = head.next

        return head




# most efficient solution (two pointers)
# we basically have a slow pointer moving by 1 and a fast pointer moving by 2, i think i've done this algorithm before
# in leetcode 141 linked list cycle

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        s = head
        f = head

        while f and f.next:
            s = s.next
            f = f.next.next
        return s

        





        
