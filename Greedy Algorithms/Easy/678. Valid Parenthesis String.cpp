class Solution {
public:
    bool checkValidString(string s) {
        int min=0;
        int maxx=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                min++;
                maxx++;
            }
            else if(s[i]==')'){
                min--;
                maxx--;
            }
            else if(s[i]=='*'){
                min--;
                maxx++;
            }

            if(maxx<0){
                return false;
            }
            min=max(min,0);
        }
        if (min==0){
            return true;
        }
        return false;
        
    }
};
