// Problem link: https://leetcode.com/problems/implement-trie-prefix-tree/description/

class TrieNode 
{
public:
    // Children are the KEY in the hashmap for a given node. Helps with fast lookups. Think of value (TrieNode) as a placeholder, it's not important.
    std::unordered_map<char, TrieNode*> children;
    bool endOfWord = false;
};

class Trie 
{
private:
    TrieNode* root;
public:
    Trie() 
    {
        root = new TrieNode();
    }
    
    // Insert a word into the Trie
    void insert(string word) 
    {
        TrieNode* curr = root;
        for (char ch : word) 
        {
            // if character is not a child of the current TrieNode we're at, create it
            if (curr->children.find(ch) == curr->children.end()) 
            {
                curr->children[ch] = new TrieNode();  
            }
            // character IS a child of the current TrieNode we're at (because we created it or it already existed), then move onto the child node
            curr = curr->children[ch];  
        }
        curr->endOfWord = true;  // Mark the end of the word
    }

    // Search for a word in the Trie
    bool search(string word) 
    {
        TrieNode* curr = root;
        for (char ch : word) 
        {
            // if character we're looking for is not a child of the current node we're on, then
            // the word we're looking for doesn't exist, return false
            if (curr->children.find(ch) == curr->children.end()) 
            {
                return false;  // Word not found
            }
            // if character IS a child of the current TrieNode we're at, then move onto the child node
            curr = curr->children[ch];
        }
        return curr->endOfWord;  // Return true if the word is valid (ends here)
    }

    // Check if there's any word in the Trie that starts with the given prefix
    bool startsWith(string prefix) 
    {
        TrieNode* curr = root;
        for (char ch : prefix) 
        {
            if (curr->children.find(ch) == curr->children.end()) 
            {
                return false;  // Prefix not found
            }
            curr = curr->children[ch];
        }
        return true;  // The prefix exists in the Trie
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
