class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int mod = num % k;
            vector<long long> ndp(k, 0);

            // Start a new subarray
            ndp[mod] = 1;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                int newR = (r * mod) % k;
                ndp[newR] += dp[r];
            }

            // Add all subarrays ending here
            for (int r = 0; r < k; r++) {
                ans[r] += ndp[r];
            }

            dp = ndp;
        }

        return ans;
    }
};