#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Trie {
public:
    Trie() {

    }

    void insert(string word) {
        Trie* node = this;
        for (const char c : word) {
            if (node->next[c - 'a'] == nullptr) {
                node->next[c - 'a'] = new Trie();
            }
            // 指向下一层节点
            node = node->next[c - 'a'];
        }
        node->is_end = true;
    }

    bool search(string word) {
        Trie* node = this;
        for (const char c : word) {
            if (node->next[c - 'a'] == nullptr) {
                return false;
            }
            node = node->next[c - 'a'];
        }
        return node->is_end;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for (const char c : prefix) {
            if (node->next[c - 'a'] == nullptr) {
                return false;
            }
            node = node->next[c - 'a'];
        }
        return true;
    }

private:
    bool is_end = false;
    std::vector<Trie*> next{26};
};
