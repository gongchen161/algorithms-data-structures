#include <memory>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <unordered_map>


class Trie {
private:
    struct TrieNode {
        std::unordered_map<char, TrieNode*> children;
        int count = 0;
    };
public:
    Trie() : root(new TrieNode) {

    }

    void insert(const std::string& s) {
        insert(root, s, 0);
    }

    int find(const std::string& s) {
        return find(root, s, 0);
    }

private:
    int find(TrieNode* node, const std::string& s, int pos) {
        if (!node) {
            return 0;
        }
        if (pos == s.size()) {
            return node->count;
        }
        return find(node->children[s[pos]], s, pos+1);
    }

    void insert(TrieNode* node, const std::string& s, int pos) {
        if (pos >= s.size()) {
             (node->count)++;   
             return;
        }
        char c = s[pos];
        if (!node->children[c]) {
            node->children[c] = new TrieNode();
        }
        insert(node->children[c], s, pos + 1);
    }

    TrieNode* root;
};



int main() {
    std::vector<std::string> vec = {"a", "abc", "abc", "abcd", "abdc", "trie", "c++"};
    Trie trie;
    for (const auto& s : vec) {
        trie.insert(s);
    }
    assert(trie.find("a") == 1);
    assert(trie.find("abc") == 2);
    assert(trie.find("abcd") == 1);
    assert(trie.find("trie") == 1);
    assert(trie.find("c++") == 1);
    assert(trie.find("c+") == 0);
    assert(trie.find("c+++") == 0);
}