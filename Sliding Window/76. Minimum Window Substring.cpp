https://leetcode.com/problems/minimum-window-substring/description/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp1;
        unordered_map<char, int> mpp2;
        for (int i = 0; i < t.size(); i++) {
            mpp1[t[i]]++;
        }
        int l = 0;
        int r = 0;
        int minSub = s.size() + 1;
        int required = mpp1.size();
        int formed = 0;
        int l1 = -1;
        int r1 = -1;

        while (r < s.size()) {
            if (mpp1.find(s[r]) != mpp1.end()) {
                mpp2[s[r]]++;

                if (mpp1[s[r]] == mpp2[s[r]]) {
                    formed++;
                }
            }
            while (formed == required) {
                int mini = r - l + 1;
                if (mini < minSub) {
                    minSub = mini;
                    l1 = l;
                    r1 = r;
                }
                if (mpp1.find(s[l]) != mpp1.end()) {
                    if (mpp2[s[l]] == mpp1[s[l]]) {
                        formed--;
                    }
                    mpp2[s[l]]--;
                }
                l++;
            }
            r++;
        }
        if (l1 == -1 && r1 == -1) {
            return "";
        }
        string ans = "";
        for (int i = l1; i <= r1; i++) {
            string str1(1,s[i]);
            ans.append(str1);
        }
        return ans;
    }
};
