#include "../../pch.h"
#include <queue>

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
	{
		m_edge.resize(numCourses);
		m_inDegree.resize(numCourses);
		for (const auto& edge : prerequisites) {
			m_edge[edge[1]].push_back(edge[0]);
			m_inDegree[edge[0]]++;
		}
		// 从入度为0的节点开始进行广度遍历
		queue<int> q;
		vector<int> path;
		for (int i = 0; i < numCourses; i++) {
			if (m_inDegree[i] == 0) {
				q.push(i);
			}
		}
		int visited = 0;
		while (!q.empty()) {
			visited++;
			int curNode = q.front();
			path.push_back(curNode);
			q.pop();
			for (const int v : m_edge[curNode]) {
				m_inDegree[v]--;
				if (m_inDegree[v] == 0) {
					q.push(v);
				}
			}
		}

		if (visited == numCourses) {
			return path;
		}
		return {};
	}

private:
	vector<vector<int>> m_edge;
	vector<int> m_inDegree;
};

// 深度优先搜索
class Solution1 {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
	{
		m_edge.resize(numCourses);
		m_visited.resize(numCourses);
		for (const auto& edge : prerequisites) {
			m_edge[edge[1]].push_back(edge[0]);
		}
		vector<int>path;
		for (int i = 0; i < numCourses && m_vaild; i++) {
			if (!m_visited[i]) {
				DFS(i, path);
			}
		}
		if (m_vaild) {
			reverse(path.begin(), path.end());
			return path;
		}
		return {};
	}

	void DFS(int i, vector<int>& path)
	{
		m_visited[i] = 1;
		for (int v : m_edge[i]) {
			// 如果该节点的边还没有被访问，则从该条边继续深入搜索
			if (m_visited[v] == 0) {
				DFS(v, path);
				if (!m_vaild) {
					return;
				}
			}
			else if (m_visited[v] == 1) {
				m_vaild = false;
				return;
			}
		}
		m_visited[i] = 2;
		path.push_back(i);
	}

private:
	vector<vector<int>> m_edge;
	vector<int> m_visited;
	bool m_vaild{ true };
};