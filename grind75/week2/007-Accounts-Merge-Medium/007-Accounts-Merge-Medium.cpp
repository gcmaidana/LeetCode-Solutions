// Problem link: https://leetcode.com/problems/accounts-merge/

class UnionFind {
public:
    vector<int> parent;

    UnionFind(int n) 
    {
        parent.resize(n);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if(parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)
    {
        parent[find(x)] = find(y);
    }
    
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int numAccounts = accounts.size();
        UnionFind uf(numAccounts);

        unordered_map<string, int> emailToAccount;   // Maps email to account index

        // Step 1: Build Union-Find structure based on shared emails
        for (int i = 0; i < numAccounts; ++i) 
        {
            for (int j = 1; j < accounts[i].size(); ++j) 
            {  // 0th index is name, not email, skip it
                string email = accounts[i][j];

                if (emailToAccount.count(email)) 
                {
                    uf.unite(i, emailToAccount[email]);
                } 
                else 
                {
                    emailToAccount[email] = i;
                }
            }
        }

        // Step 2: Group emails by root parent account
        unordered_map<int, vector<string>> accountToEmails;
        for (const auto& [email, accIdx] : emailToAccount) 
        {
            int root = uf.find(accIdx);
            accountToEmails[root].push_back(email);
        }

        // Step 3: Build final merged accounts result
        vector<vector<string>> mergedAccounts;
        for (const auto& [accIdx, emails] : accountToEmails) 
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
