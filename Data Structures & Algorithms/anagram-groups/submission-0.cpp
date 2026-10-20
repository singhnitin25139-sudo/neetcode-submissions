class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (string s : strs) {

            vector<int> freq(26, 0);

            // Count frequency of each character
            for (char ch : s) {
                freq[ch - 'a']++;
            }

            // Convert frequency array into a unique key
            string key = "";

            for (int i = 0; i < 26; i++) {
                key += to_string(freq[i]);
                key += "#";
            }

            // Same key = anagrams
            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto& it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};