class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 1;

        unordered_set<int> pairXor;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        vector<bool> vis(2048, false);

        for (int x : pairXor) {
            for (int num : nums) {
                vis[x ^ num] = true;
            }
        }

        int ans = 0;
        for (bool x : vis)
            ans += x;

        return ans;
    }
};