https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int most = 0;
        while (right < s.size()) {
            mpp[s[right]]++;
            most = max(most, mpp[s[right]]);
            if (right - left + 1 <= most + k) {
                int len = right - left + 1;
                maxLen = max(maxLen, len);
            } else {
                mpp[s[left]]--;
                left++;
            }
            right++;
        }
        return maxLen;
    }
};
