# Problem link: https://leetcode.com/problems/time-based-key-value-store/description/

class TimeMap:
    # NOTE: All the timestamps timestamp of set are strictly increasing.


    def __init__(self):
        self.hmap = {} # key : list of [val, timestamp]
        
    # set the key. for the values, set the value and timestamp together 
    # gets added to end of the list so it's O(1)
    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.hmap:
            self.hmap[key] = []
        self.hmap[key].append([value, timestamp])
        

    # keep in mind we have a pair, but we are returning only the value (str)
    # if we dont find a match, return the most recent val given the key
    # why do we use binary search? because its better than a linear scan
    # O(logN) is BETTER than O(n)
    def get(self, key: str, timestamp: int) -> str:
        ans = ""
        values = self.hmap.get(key, []) # if no key found, return empty list

        l = 0
        r = len(values) - 1
        while l <= r:
            m = (l + r) // 2

            # okay here, what we do is:
            # we want to see if we have match still so we move the pointer
            # to the right, however, this value is still valid and could be
            # the most recent so we update ans first
            if values[m][1] <= timestamp: # check midpoint timestamp
                ans = values[m][0] # set value on ans
                l = m + 1
            else:
                r = m - 1

        return ans
        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
