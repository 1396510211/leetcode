#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
	vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
		vector<vector<int>> res(n);
		map<int, vector<int>>grapha;
		for (const auto& edge : edges) {
			grapha[edge[1]].emplace_back(edge[0]);
		}
		for (int i = 0; i < n; i++) {
			vector<int> visited(n);
			queue<int> que;
			que.push(i);
			while (!que.empty())
			{
				int cur = que.front();
				que.pop();
				for (const int& before : grapha[cur]) {
					if (!visited[before]) {
						que.push(before);
						res[i].emplace_back(before);
						visited[before] = 1;
					}
				}
			}
			sort(res[i].begin(), res[i].end());
		}
		return res;
	}
};

