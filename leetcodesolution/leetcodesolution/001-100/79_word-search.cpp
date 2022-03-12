#include "../pch.h"

class Solution {
public:
	bool dfs(string word, int x, int y, int index, vector<vector<char>>& board) {
		if (index == word.size())
		{
			return true;
		}
		int dx[] = { 1,0,-1,0 };
		int dy[] = { 0,1,0,-1 };
		bool res = false;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!(nx >= 0 && ny >= 0 && nx < row && ny < col)) {
				continue;
			}
			if (word[index] == board[nx][ny] && flag[nx][ny] == false) {
				flag[nx][ny] = 1;
				if (dfs(word, nx, ny, index + 1, board)) {
					res = true;
				};
				flag[nx][ny] = 0;
			}
		}
		return res;
	}
	bool exist(vector<vector<char>>& board, string word) {
		row = board.size();
		col = board[0].size();
		if (word == "") {
			return false;
		}
		if (row == 0 || col == 0) {
			return false;
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				flag[i][j] = false;
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (board[i][j] == word[0]) {
					flag[i][j] = 1;
					if (dfs(word, i, j, 1, board)) {
						return true;
					}
					flag[i][j] = 0;
				}
			}
		}
		return false;
	}

private:
	int row;
	int col;
	bool flag[10][10];
};