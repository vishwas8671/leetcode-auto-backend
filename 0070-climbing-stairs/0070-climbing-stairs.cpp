//1. Iteration
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n <= 2) return n;
//         int a = 1;
//         int b = 2;
//         for(int i = 3; i <= n; i++) {
//             int c = a + b;
//             a = b;
//             b = c;
//         }
//         return b;
//     }
// };


//2. Recursion
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n <= 2) return n;
//         return climbStairs(n-1) + climbStairs(n-2);
//     }
// };

//3. DP / Memoization
// class Solution {
// public:
//     int solve(int n, vector<int>& dp) {
//         if(n <= 2) return n;
//         if(dp[n] != -1) return dp[n];
//         return dp[n] = solve(n-1, dp) + solve(n-2, dp);
//     }
//     int climbStairs(int n) {
//         vector<int> dp(n+1, -1);
//         return solve(n, dp);
//     }
// };


//4. Tabulation
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};