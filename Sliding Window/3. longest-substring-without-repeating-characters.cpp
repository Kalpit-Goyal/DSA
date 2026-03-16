https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int hashLen=256;
        int hash[hashLen];
        int right=0;
        int left=0;
        int maxLen=0;
        for(int i=0;i<hashLen;i++){
            hash[i]=-1;
        }
        while(right<n){
            if(hash[s[right]]!=-1){
                left=max(hash[s[right]]+1,left);
            }
            int len=right-left+1;
            maxLen=max(len,maxLen);
            hash[s[right]]=right;
            right++;
        }
        return maxLen;
        
    }
};
