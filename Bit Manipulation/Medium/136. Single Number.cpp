https://leetcode.com/problems/single-number/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1=0;
        for(int it:nums){
            xor1^=it;
        }
        return xor1;
    }
};
