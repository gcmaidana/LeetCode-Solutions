// Problem link: https://leetcode.com/problems/accounts-merge/

class UnionFind {
public:
    vector<int> par; // Parent array
    vector<int> rank; // Rank array

    UnionFind(int n) {
        par.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int find(int x) {
        if (x != par[x]) {
            par[x] = find(par[x]); // Path compression
        }
        return par[x];
    }

    bool unionSets(int x1, int x2) {
        int p1 = find(x1), p2 = find(x2);
        if (p1 == p2) {
            return false;
        }
        // Union by rank
        if (rank[p1] > rank[p2]) {
            par[p2] = p1;
        } else if (rank[p1] < rank[p2]) {
            par[p1] = p2;
        } else {
            par[p2] = p1;
            rank[p1]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        unordered_map<string, int> emailToAcc; // email -> index of account

        // Iterate over accounts to build the union-find structure
        for (int index = 0; index < n; ++index) {
            for (int j = 1; j < accounts[index].size(); ++j) { // Skip the first value (name)
                string email = accounts[index][j];
                if (emailToAcc.find(email) != emailToAcc.end()) {
                    // Perform union since we found 2 emails that belong to the same name
                    uf.unionSets(index, emailToAcc[email]);
                } else {
                    emailToAcc[email] = index;
                }
            }
        }

        unordered_map<int, set<string>> emailGroup; // index of account -> set of emails
        for (const auto& entry : emailToAcc) {
            const string& email = entry.first;
            int index = entry.second;
            int leader = uf.find(index);
            emailGroup[leader].insert(email); // Using set to avoid duplicates
        }

        vector<vector<string>> res;
        for (const auto& entry : emailGroup) {
            int index = entry.first;
            vector<string> emails(entry.second.begin(), entry.second.end()); // Convert set to vector
            sort(emails.begin(), emails.end()); // Sort emails
            emails.insert(emails.begin(), accounts[index][0]); // Insert name at the beginning
            res.push_back(emails);
        }
        return res;
    }
};
