#include "Trie.hpp"
#include <string>
#include <iostream>


Trie::Trie() :: word_count(0), root(nullptr){
    root = new TrieNode;
}

void Trie::insert(const std::string& word){
    TrieNode* cur = root;

    for (char c : word){
        int i = letterToIndex(c);

    if (cur -> children[i] == nullptr){
        cur -> children[i] = new TrieNode;
    }
    cur = cur -> children[i];
    }

    if (!cur -> end_of_word){
        cur -> end_of_word = true;
        word_count++;
    }

}
void print() const{
    string s;
    print(root, s);

}
void print(const TrieNode* node, const std::string& s) const{
if (!node){
    return;
}
else if (node-> end_of_word){
    std::cout<< s <<std::endl;
}
for (int i = 0; i < ALPHABET_SIZE; i++){
    if(!node -> children[i]){
        continue;
    }
    s += IndexToLetter(i);
    print(node -> children[i], s);
    s.pop_back();
    }
}

int Trie::letterToIndex(char c) const{
    return c - 'a'; 
}
char Trie::IndexToLetter(int i) const{
    return 'a' + i;
}


bool contains(const std::string& word) const{
    const TrieNode* cur -> root;
    for (char c : word){
        int i = letterToIndex(c);

        if (cur -> children[i]){
            return false;
        }
        cur -> children[i];
    }
    return cur -> end_of_word;
}
void getNextLetters(const std::string& prefix){
    if (nullptr){
        return;
    }
    for (char c : word){
        int i = letterToIndex(c);
    }
    if (cur -> children[i]){
         getNextLetters(node -> left)
    }
    else{}
    getNextLetters(node -> right)

    
}