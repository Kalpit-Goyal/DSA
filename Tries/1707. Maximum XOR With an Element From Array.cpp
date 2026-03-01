https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/

struct Node{
    Node* links[2]={nullptr};

    bool containsKey(int bit){
        return (links[bit]!=nullptr);
    }

    void put(int bit,Node* node){
        links[bit]=node;
    }

    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
    private:
    Node* root;

    public:
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=1 & (num>>i);
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }

    int findMax(int num){
        Node* node= root;
        int maxSum=0;
        for(int i=31;i>=0;i--){
            int bit=1&(num>>i);
            if(node->containsKey(!bit)){
                maxSum=maxSum |(1<<i);
                node=node->get(!bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxSum;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> offlineQueries;
        
        for(int i=0;i<queries.size();i++){
            offlineQueries.push_back({queries[i][1],{queries[i][0],i}});
        }
        vector<int>ans(queries.size());
        sort(offlineQueries.begin(),offlineQueries.end());
        
        int indx=0;
        int n=nums.size();
        for(auto &it:offlineQueries){
            int mi=it.first;
            int xi=it.second.first;
            int index=it.second.second;

            while(indx<n && nums[indx]<=mi){
                trie.insert(nums[indx]);
                indx++;
            }
            if(indx==0){
                ans[index]= -1;
            }
            else{
                ans[index]=trie.findMax(xi);
            }
        }
        return ans;   
    }
};
