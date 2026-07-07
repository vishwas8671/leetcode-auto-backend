// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//     }
// };

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         int i=0;
//         int j=0;
//         int k=n-1;
//         while (j <=k) {
//             if (nums[j]==1) {
//                 j++;
//             } else if (nums[j]==2) {
//                 swap (nums[j], nums[k]);
//                 k--;
//             } else { //nums[j]==1
//                 swap(nums[j], nums[i]);
//                 i++;
//                 j++;
//             }
//         }
//     }
// };


class Solution {
public:
    void sortColors(vector<int>& nums) {
       int n =nums.size();
       int count0=0, count1=0, count2=0;
       for (int i=0; i<n; i++) {
        if (nums[i]==0) {
            count0++;
        } else if (nums[i]==1) {
            count1++;
        } else {
            count2++;
        }
       }
       int idx=0;
       for (int i=0; i<count0; i++) {
            nums[idx++]=0;
       }
       for (int i=0; i<count1; i++) {
            nums[idx++]=1;
       }
       for (int i=0; i<count2; i++) {
            nums[idx++]=2;
       }
    }
};

