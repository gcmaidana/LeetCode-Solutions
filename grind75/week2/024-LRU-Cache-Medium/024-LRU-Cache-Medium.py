# https://leetcode.com/problems/lru-cache/description/

class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {} # key (value) => value (Node)

        # dummy nodes
        # so when we insert a new node, it will be between left and right
        self.left, self.right = Node(-1, -1), Node(-1, -1)
        self.left.next, self.right.prev = self.right, self.left
        
    # When we get a value, we need to put it to the end of doubly linked list
    # to mark it as most recently used, then finally we can return its value assuming it exists
    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        
        node = self.cache[key]
        self.remove(node)
        self.add(node)

        return node.val

    # if key already exists, remove the node and add back the new node with the given value
    # because this is outside of the if statement, we create the node regardless if it exists or not without issue
    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            old_node = self.cache[key]
            self.remove(old_node)

        node = Node(key, value)
        self.cache[key] = node # overwrite
        self.add(node)

        # handle capacity exceeded
        if len(self.cache) > self.capacity:
            delete_node = self.left.next
            self.remove(delete_node)
            del self.cache[delete_node.key]



    
    # for removing node from doubly linked list
    # for ex, if we have 1 -> 2 -> 3
    # 1 need to point to 3 and 3 points to 1 assuming we want to remove 2
    def remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
    
    # for adding node to doubly linked list
    # add to end of the list since we can define that as most recently used
    def add(self, node):
        prev_end = self.right.prev
        prev_end.next = node
        node.prev = prev_end
        node.next = self.right
        self.right.prev = node


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
