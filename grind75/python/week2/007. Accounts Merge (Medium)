# Problem link: https://leetcode.com/problems/accounts-merge/class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.rank = [1] * n

    def find(self, x):
        while x != self.par[x]:
            self.par[x] = self.par[self.par[x]]
            x = self.par[x]
        return x
        
    def union(self, x1, x2):
        p1, p2 = self.find(x1), self.find(x2)
        if p1 == p2:
            return False
        if self.rank[p1] > self.rank[p2]:
            self.par[p2] = p1
        elif self.rank[p1] < self.rank[p2]:
            self.par[p1] = p2
        else:
            self.par[p2] = p1
            self.rank[p1] += 1
        return True

class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:

        uf = UnionFind(len(accounts))
        emailToAcc = {} # email -> index of acc

        for index, account in enumerate(accounts):
            for email in account[1:]: # first value of an account is name, so we want to skip that

                if email in emailToAcc:
                    # perform union find since we found 2 emails that belong to the same name
                    uf.union(index, emailToAcc[email])
                else:
                    emailToAcc[email] = index
                    
        emailGroup = defaultdict(list) # index of acc -> list of emails
        for email, index in emailToAcc.items():
            leader = uf.find(index)
            emailGroup[leader].append(email)
        
        res = []
        for index, emails in emailGroup.items():
            name = accounts[index][0]
            res.append([name] + sorted(emailGroup[index])) # array concat
        return res

        
