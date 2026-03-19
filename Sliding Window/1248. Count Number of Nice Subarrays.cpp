https://leetcode.com/problems/count-number-of-nice-subarrays/description/

int numSubarraysLess(vector<int>& nums, int k) {
    if (k < 0) {
        return 0;
    }
    int l = 0;
    int r = 0;
    int count = 0;
    int num = 0;
    while (r < nums.size()) {
        if(nums[r]%2!=0){
            num++;
        }

        while (num > k) {
            if(nums[l]%2!=0){
                num--;
            }
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int a=numSubarraysLess(nums, k);
        int b=numSubarraysLess(nums, k-1);
        return (a-b);
    }
};
