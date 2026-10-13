class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        // Minimum possible eating speed
        int low = 1;

        // Maximum possible eating speed
        int high = 0;

        for (int i = 0; i < piles.size(); i++) {
            high = max(high, piles[i]);
        }

        // Binary Search
        while (low <= high) {

            // Find middle speed
            int k = low + (high - low) / 2;

            long long totalHours = 0;

            // Calculate total hours required at speed k
            for (int i = 0; i < piles.size(); i++) {

                // Ceiling division:
                // ceil(piles[i] / k)
                int hours = (piles[i] + k - 1) / k;

                totalHours = totalHours + hours;
            }

            // If Koko can finish within h hours,
            // k may be the answer.
            if (totalHours <= h) {

                // Try to find an even smaller speed
                high = k - 1;
            }
            else {

                // k is too slow,
                // so we need a bigger speed
                low = k + 1;
            }
        }

        // low will point to the minimum valid speed
        return low;
    }
};