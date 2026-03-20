https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=n-1;
        int r=k-1;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        int maxSum=sum;
        while(r>=0){
            sum=sum-cardPoints[r];
            r--;
            sum=sum+cardPoints[l];
            maxSum=max(sum,maxSum);
            l--;
        }
        return maxSum;
        
    }
};
