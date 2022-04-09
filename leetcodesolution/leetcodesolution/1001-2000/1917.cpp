#include <vector>
#include <map>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        map<int, vector<int>>m;
        if (start == end) {
            return true;
        }
        for (const auto& edge : edges) {
            m[edge[0]].emplace_back(edge[1]);
            m[edge[1]].emplace_back(edge[0]);
        }
        queue<int> que;
        que.push(start);
        unordered_set<int> visited(n);
        while (!que.empty())
        {
            int cur = que.front();
            que.pop();
            visited.insert(cur);

            for (const auto& next : m[cur]) {
                if (next == end) {
                    return true;
                }
                if (!visited.count(next)) {
                    que.push(next);
                }
            }
        }
        return false;
    }
};
