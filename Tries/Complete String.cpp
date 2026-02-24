https://www.naukri.com/code360/problems/complete-string_2687860

#include <bits/stdc++.h>
struct Node{
    Node* links[26]={nullptr};
    bool flag=false;

    bool containsKey(char ch){
        return (links[ch-'a']!=nullptr);
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setFlag(){
        flag=true;
    }
    bool getFlag(){
        return flag;
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root=new Node();
    }

    void insert(string word){
        Node* node=root;
        for(char ch:word){
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }
            node=node->get(ch);
        }
        node->setFlag();
    }
    bool isCompleteString(string it){
        Node* node = root;
        for(char ch:it){
            if(node->containsKey(ch)){
                node=node->get(ch);
                if(node->getFlag()==false){
                    return false;
                }
            }
            else return false;
        }
        return true;
    }

};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie trie;
    for(auto &it:a){
        trie.insert(it);
    }
    string longest="";
    for(auto &it: a){
        if(trie.isCompleteString(it)){
            if(it.length()>longest.length()){
                longest=it;
            }
            else if(it.length()==longest.length() && it<longest){
                longest=it;
            }
        }
    }
    if(longest==""){
        return "None";
    }
    return longest;

}
