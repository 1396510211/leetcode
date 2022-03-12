#include "../../pch.h"

class Solution {
public:
    int maxProduct(vector<string>& words)
    {
        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (!isExitSameChar(words[i], words[j])) {
                    res = max(res, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
    bool isExitSameChar(const string& a, const string& b) {
        for (char c : a) {
            if (b.find(c) != b.npos) {
                return true;
            }
        }
        return false;
    }
};