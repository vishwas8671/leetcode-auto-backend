// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int num = 1;
//         int n = arr.size();
//         int i=0;
//         while (i <n && k > 0) {
//             if (arr[i] == num) {
//                 i++;
//             } else {
//                 k--;
//             }
//             num++;
//         }
//         while (k--) {
//             num++;
//         }
//         return num-1;
        
//     }
// };

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Missing numbers before arr[mid]
            int missing = arr[mid] - (mid + 1);

            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low + k;
    }
};