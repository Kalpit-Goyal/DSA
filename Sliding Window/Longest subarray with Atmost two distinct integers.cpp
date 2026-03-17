https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int left=0;
        int right=0;
        int maxLen=0;
        unordered_map<int,int> s;
        int n=arr.size();
        
        while(right<n){
            s[arr[right]]++;
            while(s.size()>2){
                s[arr[left]]--;
                if(s[arr[left]]==0){
                s.erase(arr[left]);
                }
                left++;
            }
            int len=right-left+1;
            maxLen=max(maxLen,len);
            right++;
        }
        return maxLen;
    }
};
