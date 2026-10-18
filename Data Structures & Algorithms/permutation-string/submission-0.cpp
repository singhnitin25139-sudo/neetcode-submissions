
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        // If s1 is longer, no permutation can fit inside s2
        if (n > m) {
            return false;
        }

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Store character frequencies of s1 and first window of s2
        for (int i = 0; i < n; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        // Check the first window
        if (freq1 == freq2) {
            return true;
        }

        // Slide the window through s2
        for (int i = n; i < m; i++) {
            // Add the new character
            freq2[s2[i] - 'a']++;

            // Remove the character leaving the window
            freq2[s2[i - n] - 'a']--;

            // Check whether frequencies match
            if (freq1 == freq2) {
                return true;
            }
        }

        return false;
    }
};
