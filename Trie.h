//
// Created by Jiawei Yao on 6/4/20.
//

#ifndef TRIE_TRIE_H
#define TRIE_TRIE_H

#include <memory>
#include <vector>
#include <string>

class Trie{
public:
    Trie(): root_(new TrieNode()){}

    void insert(const std::string& word);
    bool search(const std::string& word) const;
    bool startsWith(const std::string& prefix) const;
    struct TrieNode{
        TrieNode(): is_word(false), children(26, nullptr){}
        ~TrieNode(){
            for(const auto& i : children){
                if(i)
                    delete(i);
            }
        }

        bool is_word;
        std::vector<TrieNode*> children;
    };
private:
    const TrieNode* find(const std::string& prefix) const;
    std::unique_ptr<TrieNode> root_;
};

#endif //TRIE_TRIE_H
