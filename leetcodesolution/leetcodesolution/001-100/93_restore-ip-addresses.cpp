#include "../pch.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        ans.resize(4);
        DFS(s, 0, 0);
        return res;
    }
    void DFS(const string& s, size_t pos, size_t level) {
        if (level == 4) { 
            if (pos != s.size()) {
                return;
            }
            string t;
            for (size_t i = 0;i<ans.size(); ++i) {
                t += ans[i];
                if (i != ans.size() - 1) {
                    t += ".";
                }
            }
            res.emplace_back(t);
            return;           
        }
        for (size_t i = pos; i < s.size() && i < pos + 3; ++i) {
            size_t left = pos;
            size_t right = i;
            string temp = s.substr(left, right - left + 1);
            if (stoi(temp) > 255) {
                continue;
            }
            if (s[left] == '0' && left != right) {
                continue;
            }
            ans[level] = temp;
            DFS(s, right + 1, level + 1);
        }
    }

private:
    vector<string>ans;
    vector<string>res;
};