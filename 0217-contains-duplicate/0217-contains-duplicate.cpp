// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] == nums[i - 1])
//                 return true;
//         }

//         return false;
//     }
// };

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_set<int> st;

//         for (int num : nums) {
//             if (st.count(num))
//                 return true;
//             st.insert(num);
//         }

//         return false;
//     }
// };


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;

            if (mp[num] > 1)
                return true;
        }

        return false;
    }
};