
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Treat the matrix as a sorted 1D array
        int low = 0;
        int high = m * n - 1;

        while (low <= high) {

            // Find the middle index safely
            int mid = low + (high - low) / 2;

            // Convert 1D index into 2D coordinates
            int row = mid / n;
            int col = mid % n;

            // Check whether the target is found
            if (matrix[row][col] == target) {
                return true;
            }

            // Search in the right half
            else if (matrix[row][col] < target) {
                low = mid + 1;
            }

            // Search in the left half
            else {
                high = mid - 1;
            }
        }

        // Target is not present
        return false;
    }
};
