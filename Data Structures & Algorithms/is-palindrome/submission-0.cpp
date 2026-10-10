class Solution {
public:
    bool isPalindrome(string s) {

        // Two pointers
        int left = 0;
        int right = s.length() - 1;

        // Compare characters from both ends
        while (left < right) {

            // Skip non-alphanumeric characters from the left
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // Skip non-alphanumeric characters from the right
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare characters ignoring case
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            // Move both pointers towards the center
            left++;
            right--;
        }

        // No mismatch found
        return true;
    }
};