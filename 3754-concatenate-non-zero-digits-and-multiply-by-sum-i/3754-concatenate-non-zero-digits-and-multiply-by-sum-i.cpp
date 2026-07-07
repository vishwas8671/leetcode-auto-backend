class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0;
        int sum = 0;
        int place = 1;

        while (n > 0) {
            int d = n % 10;
            if (d != 0) {
                x += d * place;
                sum += d;
                place *= 10;
            }
            n /= 10;
        }

        return 1LL * x * sum;
    }
};