
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);

        // Store the required frequency of each character in t
        for (int i = 0; i < t.size(); i++) {
            freq[t[i]]++;
        }

        int left = 0;
        int count = t.size();
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            // If this character is still required, reduce count
            if (freq[s[right]] > 0) {
                count--;
            }

            freq[s[right]]--;

            // When all required characters are included
            while (count == 0) {
                int windowLen = right - left + 1;

                // Update the minimum window
                if (windowLen < minLen) {
                    minLen = windowLen;
                    start = left;
                }

                // Remove the leftmost character from the window
                freq[s[left]]++;

                // If a required character becomes missing, window is invalid
                if (freq[s[left]] > 0) {
                    count++;
                }

                left++;
            }
        }

        // Return empty string if no valid window exists
        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};
