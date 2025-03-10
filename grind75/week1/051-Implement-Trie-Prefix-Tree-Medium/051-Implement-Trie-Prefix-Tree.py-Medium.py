# Question link: https://leetcode.com/problems/implement-trie-prefix-tree/submissions/1238630423/


class TrieNode:

    def __init__(self):
        # Children are the KEY in the hashmap for a given node. Helps with fast lookups. Think of value (TrieNode) as a placeholder, it's not important.
        self.children = {}
        self.end_of_word = False

class Trie:

    def __init__(self):
        self.root = TrieNode()
        

    def insert(self, word: str) -> None:
        # start at the top of trie 
        curr = self.root
        
        for char in word:
            # if char not a child of where we currently are in the trie,
            # create that node
            if char not in curr.children:
                curr.children[char] = TrieNode()
            # move forward to that char either after creating it (or because it already existed)
            curr = curr.children[char]

        curr.end_of_word = True


        

    def search(self, word: str) -> bool:
        # start at the top of the trie
        curr = self.root

        for char in word:
            # if character doesnt exist in trie, return false
            if char not in curr.children:
                return False
            # if character does exist, move to that next spot
            else:
                curr = curr.children[char]
        return curr.end_of_word # why return this instead of true? 
        # Consider our Trie has the word "Toaster" but we are searching "Toast". Technically "Toast" is a substring of "Toaster" but
        # "Toast" doesn't exist in our Trie. Check next function, this is where we would return true.
            
                

    def startsWith(self, prefix: str) -> bool:
        # start at the top of the trie
        curr = self.root

        for char in prefix:
            # if character doesnt exist in trie, return false
            if char not in curr.children:
                return False
            # if character does exist, move to that next spot
            else:
                curr = curr.children[char]
        return True  
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
