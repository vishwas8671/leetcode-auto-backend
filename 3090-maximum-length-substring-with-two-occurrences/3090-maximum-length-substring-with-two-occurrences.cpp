class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;
        int maxLen = 0;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            freq[s[right]]++;
            while (freq[s[right]] > 2) {
                freq[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};