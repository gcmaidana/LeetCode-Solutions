# Problem link: https://leetcode.com/problems/time-based-key-value-store/description/

class TimeMap:

    # NOTE: All the timestamps timestamp of set are strictly increasing.

    def __init__(self):
        self.hmap = {}
        
    # set the key. for the values, set the value and timestamp together
    # gets added to the end of the list so its O(1)
    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.hmap:
            self.hmap[key] = []
        
        self.hmap[key].append([value, timestamp])
        
    # Keep in mind, we have a pair (value and timestamp) but we are returning only the value (str)
    # If we don't find a match, we return the most recent value given the key
    # But we can return an empty value if we have nothing for that key
    def get(self, key: str, timestamp: int) -> str:
        ans = ""
        values = self.hmap.get(key, []) # if no key found, return empty list

        l = 0 
        r = len(values) - 1
        while l <= r:
            mid = (l + r) // 2

            # okay here, what we do is:
            # we want to see if we have a match still, so we move the pointer
            # to the right, however, this value is still valid, and could be
            # the most recent, so we update the ans first
            if values[mid][1] <= timestamp:
                ans = values[mid][0]
                l = mid + 1
            else:
                r = mid - 1
            

        return ans

        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
