// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         int l=0;
//         int r = n-1;
//         while (l <= r) {
//             int sum = nums[l] + nums[r];
//             if (sum == target) {
//                 return {l+1, r+1};
//             } else if (sum < target) {
//                 l++;
//             } else {
//                 r--;
//             }
//         }
//         return {};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};