class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            // Skip duplicates if any
            if (nums[i] == nums[i + 1])
                continue;
            int diff = nums[i + 1] - nums[i];
            if (diff > 1) {
                for (int j = 1; j < diff; j++) {
                    ans.push_back(nums[i] + j);
                }
            }
        }
        return ans;
    }
};