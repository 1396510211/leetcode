#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> paths;
		m_graph = graph;
		vector<int>path{ 0 };
		DFS(0, path, paths);
		return paths;
	}
	void DFS(int i, vector<int>& path, vector<vector<int>>& res) {
		if (i == m_graph.size() - 1) {
			res.push_back(path);
		}
		for (const auto& next : m_graph[i]) {
			path.push_back(next);
			DFS(next, path, res);
			path.pop_back();
		}
	}
private:
	vector<vector<int>> m_graph;
};
