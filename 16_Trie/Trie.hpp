#ifndef TRIE_HPP
#define TRIE_HPP
#include <string>

const int ALPHABET_SIZE = 26;

class TrieNode{
    public:
    TrieNode * children [ALPHABET_SIZE] = {};
    bool end_of_word = false;

    bool contains(const std::string& word) const;

    void getNextLetters(const std::string& word) const;
    
    // - return a string containing all possible letters 
    //that can follow the given prefix
    // Return in alphabetical order

    //need to make count words
};


class Trie{
    public:
    Trie();
    void insert(const std::string& word);
    void print() const;
    void print(const TrieNode* node, const std::string& s) const;

    private:
        TrieNode * root;
        int word_count;

        int letterToIndex(char c) const;
        char IndexToLetter(int i) const;
        
}
#endif