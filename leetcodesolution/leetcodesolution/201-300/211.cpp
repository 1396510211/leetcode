#include <string>
#include <vector>

using namespace std;

class WordDictionary {
public:
    WordDictionary() {

    }
    void addWord(string word) {
        WordDictionary* node = this;
        for (const char c : word) {
            if (node->nexts[c - 'a'] == nullptr) {
                node->nexts[c - 'a'] = new WordDictionary();
            }
            node = node->nexts[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return search(word, this);
    }
    bool search(string word, WordDictionary* node) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                for (const auto& it : node->nexts) {
                    if (it != nullptr) {
                        if (search(word.substr(i+1), it)) {
                            return true;
                        }
                    }
                }
                return false;
            }
            else {
                if (node->nexts[word[i] - 'a'] == nullptr) {
                    return false;
                }
                node = node->nexts[word[i] - 'a'];
            }
        }
        return node->isEnd;
    }
private:
    std::vector<WordDictionary* > nexts{26};
    bool isEnd{ false };
};
 
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */