#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
	{
		m_visited.resize(numCourses);
		for (const auto& info : prerequisites) {
			m_edge[info[1]].push_back(info[0]);
		}
		for (int i = 0; i < numCourses && m_vaild; i++) {
			if (!m_visited[i]) {
				DFS(i);
			}
		}
		return m_vaild;
	}

	void DFS(int i)
	{
		m_visited[i] = 1;
		for (int v : m_edge[i]) {
			// 如果该节点的边还没有被访问，则从该条边继续深入搜索
			if (m_visited[v] == 0) {
				DFS(v);
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
	}

private:
	map<int, vector<int>> m_edge;
	vector<int> m_visited;
	bool m_vaild = true;
};

class Solution1
{
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
	{
		m_inDegree.resize(numCourses);
		for (auto& info : prerequisites) {
			m_edge[info[1]].push_back(info[0]);
			m_inDegree[info[0]]++;
		}
		// 找到入度为0的课程 表示该课程不需要前序课程
		queue<int> q;
		for (int i = 0; i < numCourses; i++) {
			if (m_inDegree[i] == 0) {
				q.push(i);
			}
		}
		int visited = 0;
		while (!q.empty()) {
			visited++;
			int cur = q.front();
			q.pop();
			for (int v : m_edge[cur]) {
				--m_inDegree[v];
				if (m_inDegree[v] == 0) {
					q.push(v);
				}
			}
		}
		return visited == numCourses;
	}

private:
	map<int, vector<int>> m_edge;
	vector<int> m_inDegree;
};