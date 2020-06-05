#include "Trie.h"
//
// Created by Jiawei Yao on 6/4/20.
//
void Trie::insert(const std::string &word) {
    auto tmp = root_.get();
    for(const auto i : word){
        if(!tmp -> children[i - 'a']){
            tmp -> children[i - 'a'] = new TrieNode();
        }
        tmp = tmp -> children[i - 'a'];
    }
    tmp -> is_word = true;
}

bool Trie::startsWith(const std::string &prefix) const {
    return find(prefix) != nullptr;
}

bool Trie::search(const std::string &word) const {
    const TrieNode* p = find(word);
    return p && p->is_word;
}

const Trie::TrieNode* Trie::find(const std::string &prefix) const {
    const TrieNode* p = root_.get();
    for(const auto i : prefix){
        p = p -> children[i - 'a'];
        if(p == nullptr)
            break;
    }
    return p;
}