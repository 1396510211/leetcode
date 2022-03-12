#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap)
	{
		const int row = heightMap.size();
		const int col = heightMap[0].size();

		if (row < 3 || col < 3) {
			return 0;
		}

		// 建立优先队列
		auto cmp = [&](const vector<int>& a, const vector<int>& b) {return a[2] > b[2]; };
		priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

		vector<vector<bool>> visited(row, vector<bool>(col));

		for (int i = 0; i < row; i++) {
			pq.push({ i,0,heightMap[i][0] });
			visited[i][0] = true;
			pq.push({ i,col - 1,heightMap[i][col - 1] });
			visited[i][col - 1] = true;
		}

		for (int j = 1; j < col - 1; j++) {
			pq.push({ 0,j,heightMap[0][j] });
			visited[0][j] = true;
			pq.push({ row - 1,j,heightMap[row - 1][j] });
			visited[row - 1][j] = true;
		}

		int res = 0;
		while (!pq.empty()) {
			auto cur = pq.top();
			pq.pop();
			vector<int> dir{ -1,0,1,0, -1 };
			for (int i = 0; i < 4; i++) {
				int nextX = cur[0] + dir[i];
				int nextY = cur[1] + dir[i + 1];
				if (nextX >= 0 && nextX < row && nextY >= 0 && nextY < col && !visited[nextX][nextY]) {
					int tmp = cur[2] - heightMap[nextX][nextY];
					if (tmp > 0) {
						res += tmp;
					}
					pq.push({ nextX, nextY, (int)max(heightMap[nextX][nextY], cur[2]) });
					visited[nextX][nextY] = true;
				}
			}
		}
		return res;
	}
};