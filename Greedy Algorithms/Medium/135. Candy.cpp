class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        int ans=1;
        int rate=1;
        int neg=1;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                rate++;
                ans=ans+rate;
            }
            else if(ratings[i]<ratings[i-1]){
                if(neg==rate){
                    neg++;
                }
                ans=ans+neg;
                neg++;
                if((i+1)<ratings.size() && ratings[i]<ratings[i+1] ){
                    rate=1;
                    neg=1;
                }
            }
            else if(ratings[i]==ratings[i-1]){
                rate=1;
                neg=1;
                ans=ans+rate;
            }


        }
        return ans;

        
    }
};
