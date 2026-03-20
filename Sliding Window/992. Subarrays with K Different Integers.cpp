https://leetcode.com/problems/subarrays-with-k-different-integers/description/

int subarrayWithLessThanK(vector<int>& nums, int k){
    int n=nums.size();
    int l=0;
    int r=0;
    int maxSub=0;
    unordered_map<int,int> mpp;
    while(r<n){
        mpp[nums[r]]++;
        while(mpp.size()>k){
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0){
                mpp.erase(nums[l]);
            }
            l++;
        }
        if(mpp.size()<=k){
            int sub=r-l+1;
            maxSub+=sub;
        }
        r++;
    }
    return maxSub;
        
}
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a=subarrayWithLessThanK(nums,k);
        int b=subarrayWithLessThanK(nums,k-1);
        return (a-b);
       
    }
};
