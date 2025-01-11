#include<iostream>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26]; //ek node ka 26 childern
    bool isTerminal ; // last wala node hai ki nahi 
    //constructor 
    TrieNode(char ch){
        data = ch;
        for(int i = 0 ; i < 26 ; i++){
            children[i] =  NULL;

        }
        isTerminal = false;

    }

};

class Trie {
    public:
    TrieNode*root;

    void insertutil(TrieNode* root , string word){
        //basse case
        if(word.length() == 0){
            root->isTerminal = true; // last wala word hai kisi bhi string ka 
            return;
        }
        //assumption , word will be in capital letter
        int index = word[0] - 'A'; //you will get index whwee to insert
        TrieNode*child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];


        }
        else{
            //absent
            child = new TrieNode(word[0]); // agaar word present nahi hai to ek node bana do us wordd ka
            root->children[index] = child; //root ke childrem wale inex me us word node ko dal do
        }
        // yahi kam recursivly karte jo
        insertutil(child , word.substr(1));

    }
    void insertword(string word){
        insertutil(root , word);

    }
    bool searchutil(TrieNode* root , string word){
        //basse case
        if(word.length() == 0){
            root->isTerminal ; // last wala word agar mil gya seach kaarte lkatre matlab word present hai
            return;
        }
       
        int index = word[0] - 'A'; //you will get index whwee to insert
        TrieNode*child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];


        }
        else{
            //absent
            return false;
        }
        // yahi kam recursivly karte jo
       return searchutil(child , word.substr(1));

    }
    bool search(string word){
       return searchutil(root , word);

    }



};
 int main(){
    Trie * t = new Trie();
    t->insertword("ABCD");
    
 }