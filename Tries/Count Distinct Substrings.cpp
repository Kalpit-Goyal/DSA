https://www.naukri.com/code360/problems/count-distinct-substrings_985292

struct Node{
    Node* links[26]={nullptr};

    bool containsKey(char ch){
        return (links[ch-'a']!=nullptr);
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Node* root=new Node();
    int cnt=0;

    for(int i=0;i<s.length();i++){
        Node* node=root;
        for(int j=i;j<s.length();j++){
            if(!node->containsKey(s[j])){
                cnt++;
                node->put(s[j],new Node());
            }
            node=node->get(s[j]);
        }
    }
    return (cnt+1);

}
