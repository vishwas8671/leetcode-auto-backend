class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();

        vector<int> count(26, 0);

        // Count frequency of every character
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }

        bool possible = true;
        int odd = 0;

        // Check whether a palindrome is possible
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 == 1) {
                odd++;
            }
        }

        if (odd > 1)
            possible = false;

        else if (odd == 1 && n % 2 == 0)
            possible = false;

        if (!possible)
            return "";

        // Find the middle character
        char midvalue = 0;

        if (n % 2 == 1) {
            int oddindex = -1;

            for (int i = 0; i < 26; i++) {
                if (count[i] % 2 == 1) {
                    oddindex = i;
                    break;
                }
            }

            midvalue = char('a' + oddindex);

            count[oddindex]--;
        }

        int half = n / 2;

        // Try to use target's first half
        for (int i = 0; i < half; i++) {
            count[target[i] - 'a'] -= 2;
        }

        // If target's first half can be formed
        if (check(count)) {

            string head = target.substr(0, half);

            string rev = head;
            reverse(rev.begin(), rev.end());

            string tail = "";

            if (midvalue != 0)
                tail += midvalue;

            tail += rev;

            // head + tail is the palindrome
            if (tail > target.substr(half)) {
                return head + tail;
            }
        }

        // Target's first half either cannot be formed
        // or produces a palindrome smaller than target.
        //
        // So we go backwards and try to make one character larger.

        for (int i = half - 1; i >= 0; i--) {

            char w = target[i];

            // Restore the character that we previously used
            count[w - 'a'] += 2;

            if (!check(count))
                continue;

            // Try a character larger than target[i]
            for (int j = (w - 'a') + 1; j < 26; j++) {

                if (count[j] < 2)
                    continue;

                // Use this larger character
                count[j] -= 2;

                // Keep target's prefix before i
                string res = target.substr(0, i);

                // Put the larger character at position i
                res += char('a' + j);

                // Fill remaining positions with
                // the smallest possible characters
                for (int k = 0; k < 26; k++) {

                    int cnt = count[k] / 2;

                    if (cnt > 0) {
                        res.append(cnt, char('a' + k));
                    }
                }

                // Mirror the first half
                string part = res;
                reverse(part.begin(), part.end());

                if (midvalue != 0)
                    res += midvalue;

                res += part;

                return res;
            }
        }

        return "";
    }

    bool check(vector<int>& count) {
        for (int i = 0; i < 26; i++) {
            if (count[i] < 0)
                return false;
        }

        return true;
    }
};