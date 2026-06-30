class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l=0, r=0, count=0;
        int countA=0, countB=0, countC=0;
        for (r=0; r < n; r++) {
            if (s[r]=='a') countA++;
            if (s[r]=='b') countB++;
            if (s[r]=='c') countC++;
            while (countA > 0 && countB > 0 && countC > 0) {
                count = count +  (n-r);
                if (s[l]=='a') countA--;
                if (s[l]=='b') countB--;
                if (s[l]=='c') countC--;
                l++;
            }
        }
        return count;
    }
    
};