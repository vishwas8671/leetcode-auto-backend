//1. Iteration — Optimal O(n²)
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n,1);
//         int ans=1;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<i;j++){
//                 if(nums[j]<nums[i]){
//                     dp[i]=max(dp[i],dp[j]+1);
//                 }
//             }
//             ans=max(ans,dp[i]);
//         }
//         return ans;
//     }
// };



// 2. Recursion
// class Solution {
// public:
//     int solve(vector<int>& nums,int i,int prev){
//         if(i==nums.size()) return 0;
//         int take=0;
//         if(prev==-1 || nums[i]>nums[prev])
//             take=1+solve(nums,i+1,i);
//         int skip=solve(nums,i+1,prev);
//         return max(take,skip);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         return solve(nums,0,-1);
//     }
// };



// 3. DP / Memoization
// class Solution {
// public:
//     int solve(vector<int>& nums,int i,int prev,vector<vector<int>>& dp){
//         if(i==nums.size()) return 0;
//         if(dp[i][prev+1]!=-1) return dp[i][prev+1];
//         int take=0;
//         if(prev==-1 || nums[i]>nums[prev])
//             take=1+solve(nums,i+1,i,dp);
//         int skip=solve(nums,i+1,prev,dp);
//         return dp[i][prev+1]=max(take,skip);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         return solve(nums,0,-1,dp);
//     }
// };



//4. Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int take=0;
                if(prev==-1 || nums[i]>nums[prev])
                    take=1+dp[i+1][i+1];
                int skip=dp[i+1][prev+1];
                dp[i][prev+1]=max(take,skip);
            }
        }
        return dp[0][0];
    }
};