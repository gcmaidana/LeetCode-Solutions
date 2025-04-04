// Problem link: https://leetcode.com/problems/time-based-key-value-store/description/

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TimeMap {
private:
    // key -> vector of pairs of (value, timestamp)
    unordered_map<string, vector<pair<string, int>>> hmap;

public:
    TimeMap() 
    {
        // Constructor
    }


    void set(string key, string value, int timestamp) 
    {
        hmap[key].emplace_back(value, timestamp); // O(1) append
    }

    string get(string key, int timestamp)     
{
        string ans = "";
        auto& values = hmap[key]; // Get the vector of (value, timestamp) pairs

        int l = 0, r = values.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (values[m].second <= timestamp) 
            {
                ans = values[m].first;
                l = m + 1;
            } 
            else 
            {
                r = m - 1;
            }
        }

        return ans;
    }
};
