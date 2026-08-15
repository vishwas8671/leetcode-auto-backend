class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int resultxor=0;
        int allZero=true;
        for(int &x : nums) {
            resultxor = resultxor ^ x;
            if (x != 0) {
                allZero=false;
            }
        }
        if (allZero) {
            return 0;
        }
        return resultxor ==0 ? n-1 : n;
    }

};