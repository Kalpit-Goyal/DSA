
class Solution {
  public:
  static bool comp(pair<double,int> a, pair<double,int> b){
            return a.first>b.first;
        }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<pair<double,int>> items;
        for(int i=0;i<n;i++){
            double ratio=(double)val[i]/wt[i];
            items.push_back({ratio,i});
        }
        sort(items.begin(),items.end(),comp);
        
        double final=0.0;
        
        for(auto &it:items){
            if(wt[it.second]<=capacity){
                final+=val[it.second];
                capacity-=wt[it.second];
            }
            else{
                final+=it.first*capacity;
                break;
            }
        }
        return final;
    }
};
