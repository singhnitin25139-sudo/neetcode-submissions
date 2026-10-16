
class TimeMap {
private:
    // key -> list of (timestamp, value)
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        // Store timestamp and value for this key
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        // If key does not exist, return empty string
        if (mp.find(key) == mp.end()) {
            return "";
        }

        vector<pair<int, string>>& arr = mp[key];

        int low = 0;
        int high = arr.size() - 1;
        string ans = "";

        // Find the largest timestamp <= given timestamp
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid].first <= timestamp) {
                ans = arr[mid].second;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
