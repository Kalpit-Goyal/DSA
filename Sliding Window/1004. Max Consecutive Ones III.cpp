https://leetcode.com/problems/max-consecutive-ones-iii/description/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen=0;
        int right=0;
        int left=0;
        int zeroes=0;

        while(right<nums.size()){
            if(nums[right]==0){
                zeroes++;
            }
            if(zeroes<=k){
                int len=right-left+1;
                maxLen=max(len,maxLen);
            }
            else{
                if(nums[left]==0){
                    zeroes--;
                }
                left++;
            }
            right++;
        }
        return maxLen;
    }
};
