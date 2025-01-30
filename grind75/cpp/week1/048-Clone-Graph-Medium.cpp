// Problem link: https://leetcode.com/problems/clone-graph/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    std::unordered_map<Node*, Node*> clone;

    Node* dfs(Node* node)
    {
        if(clone.count(node)) 
        {
            return clone[node];
        }

        Node* copy = new Node(node->val);
        clone[node] = copy;

        for(Node* neighbor : node->neighbors)
        {
            copy->neighbors.push_back(dfs(neighbor));   
        }


        return copy;
        

    }


    Node* cloneGraph(Node* node) {

        if(!node) { return NULL; }

        return dfs(node);
    
        
        
    }
};
