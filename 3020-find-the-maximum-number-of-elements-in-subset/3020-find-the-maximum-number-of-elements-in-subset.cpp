class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int x : nums) cnt[x]++;

        int ans = 0;

        // Handle 1 separately
        if (cnt.count(1)) {
            ans = (cnt[1] % 2) ? cnt[1] : cnt[1] - 1;
        }

        for (auto &[x, f] : cnt) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (cnt[cur] >= 2 && cnt.count(cur * cur)) {
                len += 2;
                if (cur > 1000000000LL) break; // prevent overflow
                cur *= cur;
            }

            if (cnt[cur] >= 1)
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};