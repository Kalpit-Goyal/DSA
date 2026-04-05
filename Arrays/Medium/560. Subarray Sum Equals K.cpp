https://leetcode.com/problems/subarray-sum-equals-k/submissions/1969532372/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int count=0;
        int Presum=0;
        for(int i=0;i<nums.size();i++){
            Presum=Presum+nums[i];
            int remain=Presum-k;
            count+=mpp[remain];
            mpp[Presum]++;
        }
        return count;
    }
};
