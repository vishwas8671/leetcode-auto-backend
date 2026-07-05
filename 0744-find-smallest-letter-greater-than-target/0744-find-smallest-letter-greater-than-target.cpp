// class Solution {
// public:
//     char nextGreatestLetter(vector<char>& letters, char target) {
//         int n = letters.size();
//         int l=0;
//         int r=n-1;
//         int mid;
//         int pos=-1;
//         while (l <=r) {
//             mid = l+(r-l)/2;
//             if (letters[mid] > target) {
//                 pos=mid;
//                 r=mid-1;
//             } else {
//                 l=mid+1;
//             }
//         }
//         if(pos==-1) {
//             return letters[0];
//         }
//         return letters[pos];

//     }
// };


class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int idx = upper_bound(begin(letters), end(letters),target)-begin(letters);
        if(idx==letters.size()) {
            return letters[0];
        }
        return letters[idx];

    }
};
