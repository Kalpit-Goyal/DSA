https://www.naukri.com/code360/problems/implement-trie_1387095

#include <bits/stdc++.h> 
struct Node{
    Node *links[26]={nullptr};
    int countPre=0;
    int countWord=0;

    bool containsKey(char ch){
        return (links[ch-'a']!=nullptr);
    }

    void put(char ch,Node* node){
        links[ch-'a']=node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }
    void increaseWord(){
        countWord++;
    }
    void increasePre(){
        countPre++;
    }
    void deletePre(){
        countPre--;
    }
    void deleteWord(){
        countWord--;
    }

};

class Trie{
    Node* root;

    public:

    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        // Write your code here
        Node* node=root;
        for(char ch:word){
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }
            node=node->get(ch);
            node->increasePre();
        }
        node->increaseWord();

    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node=root;
        for(char ch:word){
            if(node->containsKey(ch)){
                node=node->get(ch);
            }
            else{
                return 0;
            }
        }
        return node->countWord;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node=root;
        for(char ch:word){
            if(node->containsKey(ch)){
                node=node->get(ch);
            }
            else{
                return 0;
            }
        }
        return node->countPre;
    }
    

    void erase(string &word){
        // Write your code here.
        Node* node=root;
        for(char ch:word){
            if(node->containsKey(ch)){
                node=node->get(ch);
                node->deletePre();
            }
            else{
                return;
            }
        }
        node->deleteWord();
    }
};
