// Problem link: https://leetcode.com/problems/accounts-merge/
// Create Union Find Class
class UnionFind {
public:
    vector<int> parents;
    
    // Initialize each node to be its own parent
    UnionFind(int n) 
    {
        parents.resize(n);
        for(int i = 0; i < n; i++)
        {
            parents[i] = i;
        }
    }

    // Find the root parent of node x with path compression
    int find(int x)
    {
        if(parents[x] != x)
        {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    // Connect the sets containing 'child' and 'parent' by 
    // pointing the root of 'child' to the root of 'parent'
    void unite(int child, int parent)
    {
        parents[find(child)] = find(parent);
    }
    
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int numAccounts = accounts.size();
        UnionFind uf(numAccounts);

        unordered_map<string, int> emailToAccount; // Maps email to account index
        
        // Build the Union-Find data structure based on shared emails
        for(int i = 0; i < numAccounts; i++)
        {
            for(int j = 1; j < accounts[i].size(); j++)
            {   // 0th index is name, not email, skip it
                string email = accounts[i][j];

                if(emailToAccount.count(email)) // Email already seen before
                {
                    uf.unite(i, emailToAccount[email]);
                }
                else // This email has never been seen before, add email as key, acc idx as value
                {
                    emailToAccount[email] = i;
                }
            }
        }

        // Group emails by root parent account
        unordered_map<int, vector<string>> accountToEmails;
        for(const auto& [email, accIdx] : emailToAccount)
        {
            cout << "email im on: " << email << endl;
            cout << "account index: " << accIdx << endl;
            cout << "Leader index: " << uf.find(accIdx) << endl;
            int root = uf.find(accIdx);
            accountToEmails[root].push_back(email);
        }

        // Build final merged accounts result
        vector<vector<string>> mergedAccounts;
        for(const auto& [accIdx, emails] : accountToEmails)
        {
            string name = accounts[accIdx][0];
            vector<string> sortedEmails = emails;
            sort(sortedEmails.begin(), sortedEmails.end());

            vector<string> merged = { name };
            merged.insert(merged.end(), sortedEmails.begin(), sortedEmails.end());

            mergedAccounts.push_back(merged);
        }

        return mergedAccounts;
    }
};
