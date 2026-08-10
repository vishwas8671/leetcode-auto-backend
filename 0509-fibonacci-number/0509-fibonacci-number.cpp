//Using iteration
// class Solution {
// public:
//     int fib(int n) {
//         if(n <= 1) return n;
//         int a = 0;
//         int b = 1;
//         for(int i = 2; i <= n; i++) {
//             int c = a + b;
//             a=b;
//             b=c;
//         }
//         return b;
//     }
// };


//Using Recursion...
// class Solution {
// public:
//     int fib(int n) {
//         if(n <=1) return n;
//         else return fib(n-1) + fib(n-2);
//     }
// };


//using DP
// class Solution {
// public:
//     int fib(int n, vector<int>& dp) {
//         if(n <= 1) return n;
//         if(dp[n] != -1)
//             return dp[n];
//         return dp[n] = fib(n-1, dp) + fib(n-2, dp);
//     }
//     int fib(int n) {
//         vector<int> dp(n+1, -1);
//         return fib(n, dp);
//     }
// };


// using tabulation
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};


