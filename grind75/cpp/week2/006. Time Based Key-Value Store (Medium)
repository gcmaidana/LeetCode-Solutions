// Problem link: https://leetcode.com/problems/time-based-key-value-store/description/

class TimeMap {
public:
// Store data with key as a string and a vector of pairs {value, timestamp}
std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> store;

    TimeMap() {
    
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
         if (store.find(key) == store.end()) {
            return "";  // If the key doesn't exist, return an empty string
        }

        const std::vector<std::pair<std::string, int>>& values = store[key];

        // Binary search to find the right value at or before the timestamp
        int l = 0, r = values.size() - 1;
        std::string ans = "";

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (values[m].second <= timestamp) {
                ans = values[m].first;
                l = m + 1;  // Continue searching in the right half
            } else {
                r = m - 1;  // Continue searching in the left half
            }
        }

        return ans;  // Return the found answer or an empty string if none fits
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
