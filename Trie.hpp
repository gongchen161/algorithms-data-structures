#include <memory>
#include <vector>
#include <string>
#include <map>
#include <iostream>

class Trie {
private:  
    class TrieNode{
    public:
        std::map<char, TrieNode*> _child;
        int _count;

        TrieNode() : _count(0){}
    };
public:
    Trie() : _root(new TrieNode) {}

    //add a string to the Trie
    void insert(const std::string& s) {

        TrieNode* cur = _root;
        _root->_count++;
        for (int i = 0; i<s.size(); i++) {
            if (cur->_child[s[i]] == nullptr) {
                cur->_child[s[i]] = new TrieNode();
            }
            cur->_child[s[i]]->_count++;
            cur = cur->_child[s[i]];
        }
    }

    //Find how many strings with the prefix s
    int find_count(const std::string& s) {

        TrieNode* cur = _root;
        for (int i = 0; i<s.size(); i++) {
            cur = cur->_child[s[i]];
            if (cur == nullptr)
            return 0;
        }

        return cur->_count;
    }
private:
    TrieNode* _root;
};
