#include <vector>
#include <map>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res = 0;
        const size_t size = isConnected.size();
        vector<int> visited(size);
        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                dfs(isConnected,visited,i);
            }
            res++;
        }
        return res;
    }
    void dfs(vector<vector<int>>& isConnected, vector<int>visited, int begin) {
        for (int i = 0; i < isConnected.size(); i++) {
            const int connected = isConnected[begin][i];
            if (connected == 1&&!visited[connected]) {
                visited[begin] = 1;
                dfs(isConnected, visited, isConnected[begin][i]);
            }
        }
    }
};
