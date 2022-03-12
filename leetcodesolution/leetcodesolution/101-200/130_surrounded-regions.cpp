#include "../pch.h"

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		row = board.size();
		col = board[0].size();
		flag.resize(row);
		for (auto& it : flag) {
			it.resize(col);
		}
		for (size_t i = 0; i < row; i++) {
			for (size_t j = 0; j < col; j++) {
				if (board[i][j] == 'O' && flag[i][j] == false) {
					vector<pair<int, int>> ranges;
					DFS(board, i, j, ranges);
					if (!isContainEdge(ranges)) {
						for (const auto& it : ranges) {
							board[it.first][it.second] = 'X';
						}
					}
				}
			}
		}
	}

	void DFS(vector<vector<char>>& board, size_t x, size_t y, vector<pair<int, int>>& ranges) {
		if (board[x][y] == 'O') {
			ranges.push_back({ x,y });
		}
		int dx[] = { 1,0,-1,0 };
		int dy[] = { 0,1,0,-1 };
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!(nx >= 0 && ny >= 0 && nx < row && ny < col)) {
				continue;
			}
			if (board[nx][ny] == 'O' && flag[nx][ny] == false) {
				flag[nx][ny] = true;
				DFS(board, nx, ny, ranges);
			}
		}
	}
	bool isContainEdge(vector<pair<int, int>> ranges) {
		for (const auto& it : ranges) {
			if (it.first == 0 || it.first == row - 1) {
				return true;
			}
			if (it.second == 0 || it.second == col - 1) {
				return true;
			}
		}
		return false;
	}
private:
	size_t row;
	size_t col;
	vector<vector<size_t>> flag;
};