//1. Iteration — O(n) Time, O(1) Space
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         if(n == 2) return min(cost[0], cost[1]);
//         int a = cost[0];
//         int b = cost[1];
//         for(int i = 2; i < n; i++) {
//             int c = cost[i] + min(a,b);
//             a = b;
//             b = c;
//         }
//         return min(a,b);
//     }
// };
//cost[i] + min(cost[i-1] wala path, cost[i-2] wala path)


//2. Recursion — O(2ⁿ) Time, O(n) Space
// class Solution {
// public:
//     int solve(vector<int>& cost,int i) {
//         if(i >= cost.size()) return 0;
//         return cost[i] + min(solve(cost,i+1),solve(cost,i+2));
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         return min(solve(cost,0),solve(cost,1));
//     }
// };


//3. DP / Memoization — O(n) Time, O(n) Space
// class Solution {
// public:
//     int solve(vector<int>& cost,int i,vector<int>& dp) {
//         if(i >= cost.size()) return 0;
//         if(dp[i] != -1) return dp[i];
//         return dp[i] = cost[i] + min(solve(cost,i+1,dp),solve(cost,i+2,dp));
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n,-1);
//         return min(solve(cost,0,dp),solve(cost,1,dp));
//     }
// };

//4. Tabulation — O(n) Time, O(n) Space
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};