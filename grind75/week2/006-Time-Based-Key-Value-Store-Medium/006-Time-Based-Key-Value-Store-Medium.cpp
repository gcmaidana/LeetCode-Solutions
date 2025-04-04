// Problem link: https://leetcode.com/problems/time-based-key-value-store/description/


class TimeMap {
    // NOTE: All the timestamps timestamp of set are strictly increasing.

private:
    unordered_map<string, vector<pair<string, int>>> hmap; // key : list of [val, timestamp]

public:
    TimeMap() {
        // constructor
    }

    // set the key. for the values, set the value and timestamp together 
    // gets added to end of the list so it's O(1)
    void set(string key, string value, int timestamp) {
        if (hmap.find(key) == hmap.end()) {
            hmap[key] = vector<pair<string, int>>();
        }
        hmap[key].push_back({value, timestamp});
    }

    // keep in mind we have a pair, but we are returning only the value (str)
    // if we dont find a match, return the most recent val given the key
    // why do we use binary search? because its better than a linear scan
    // O(logN) is BETTER than O(n)
    string get(string key, int timestamp) {
        string ans = "";
        vector<pair<string, int>>& values = hmap[key]; // if no key found, return empty list

        int l = 0;
        int r = values.size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;

            // okay here, what we do is:
            // we want to see if we have match still so we move the pointer
            // to the right, however, this value is still valid and could be
            // the most recent so we update ans first
            if (values[m].second <= timestamp) { // check midpoint timestamp
                ans = values[m].first; // set value on ans
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans;
    }
};
