
class Solution {
public:
    int solve(int i, vector<int>& cost, vector<int>& dp) {
        // Base cases
        if (i == 0) {
            return cost[0];
        }

        if (i == 1) {
            return cost[1];
        }

        // If already calculated, return stored answer
        if (dp[i] != -1) {
            return dp[i];
        }

        // Take one step from i-1
        int oneStep = solve(i - 1, cost, dp);

        // Take two steps from i-2
        int twoStep = solve(i - 2, cost, dp);

        // Store and return the minimum cost
        dp[i] = cost[i] + min(oneStep, twoStep);

        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // Initialize DP array with -1
        vector<int> dp(n, -1);

        // Minimum cost to reach the top
        return min(solve(n - 1, cost, dp),
                   solve(n - 2, cost, dp));
    }
};
