#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
	int jump(vector<int>& nums) {
		queue<int> que;
		que.push(0);
		int step = 0;
		set<int> visited;
		while (!que.empty()) {
			queue<int> nexts;
			while (!que.empty()) {
				int cur = que.front();
				que.pop();
				for (int i = cur + 1; i <= cur + nums[cur] && i < nums.size(); i++) {
					if (i == nums.size() - 1) {
						return step;
					}
					else if (visited.count(i) == 0) {
						nexts.push(i);
						visited.insert(i);
					}
				}
			}
			step++;
			que = nexts;
		}
		return 0;
	}
};