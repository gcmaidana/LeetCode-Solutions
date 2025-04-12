# Problem link: https://leetcode.com/problems/accounts-merge/class UnionFind:
    # Create Union Find class
class UF:
    def __init__(self, N): # N = number of nodes
        self.parents = list(range(N))

    def find(self, x):
        if x != self.parents[x]: # if x is not its own parent
            self.parents[x] = self.find(self.parents[x]) # path compression
        return self.parents[x]

    def union(self, child, parent):
        self.parents[self.find(child)] = self.find(parent)


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        uf = UF(len(accounts))
        emailGroup = defaultdict(list) # idx of acc => list of emails
        email_to_name = {}

        # The first value is always the account name, then the emails
        # So skip the first value
        for accIdx, account in enumerate(accounts):
            for email in account[1:]:

                if email in email_to_name:
                    # If this exists, the current accIdx and the one we inserted previously need to be
                    # unioned
                    uf.union(accIdx, email_to_name[email])
                else:
                    email_to_name[email] = accIdx
        
        for email, accIdx in email_to_name.items():
            leader = uf.find(accIdx)
            emailGroup[leader].append(email)

        # Remember the output has to be sorted in a specific way
        ans = []
        for accIdx, emails in emailGroup.items():
            name = accounts[accIdx][0]
            ans.append([name] + sorted(emailGroup[accIdx]))
        
        return ans
