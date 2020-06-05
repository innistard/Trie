#include <iostream>
#include "Trie.h"

int main() {
    //td::cout << "Hello, World!" << std::endl;
    Trie trie;
    std::string s1 = "apple", s2 = "app";
    trie.insert(s1);
    trie.insert("book");
    std::cout << "start with " << s2 << " " << trie.startsWith(s2) << std::endl;
    std::cout << "search " << "book" << " " << trie.search("boo") << std::endl;
    return 0;
}