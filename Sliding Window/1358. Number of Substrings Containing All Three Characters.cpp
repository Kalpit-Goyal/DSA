https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0;
        int r=0;
        int arr[3]={0,0,0};
        int count=0;
        while(r<s.size()){
            arr[s[r]-'a']++;
            while(arr[0]>0 && arr[1]>0 && arr[2]>0){
                count+=(s.size()-r);
                arr[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return count;
        
    }
};
