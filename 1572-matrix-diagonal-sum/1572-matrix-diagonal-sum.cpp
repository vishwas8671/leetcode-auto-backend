// class Solution {
// public:
//     int diagonalSum(vector<vector<int>>& mat) {
//         int row=0;
//         auto lambda = [&](int sum, vector<int>vec) {
//             sum += vec[row];
//             if(row != vec.size()-row-1) {
//                 sum+= vec[vec.size()-row-1];
//             }
//             row++;
//             return sum;
//         };
//         int result = accumulate(begin(mat), end(mat), 0, lambda);
//         return result;
//     }
// };

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += mat[i][i];             // Primary diagonal
            sum += mat[i][n - 1 - i];     // Secondary diagonal
        }

        // If n is odd, center element is counted twice
        if (n % 2 == 1) {
            sum -= mat[n / 2][n / 2];
        }

        return sum;
    }
};