#include <vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        int res = 0;
        vector<vector<int>> vec(n, vector<int>(n));

        for (const auto& it : dig) {
            vec[it[0]][it[1]] = 1;
        }
        for (const auto& artifact : artifacts) {
            int r1, r2, c1, c2;
            r1 = artifact[0];
            c1 = artifact[1];
            r2 = artifact[2];
            c2 = artifact[3];
            bool isCovered = true;;
            for (int i = min(r1, r2); i <= max(r1, r2); i++) {
                for (int j = min(c1, c2); j <= max(c1, c2); j++) {
                    if (vec[i][j] == 0) {
                        isCovered = false;
                        break;
                    }
                }
            }
            if (isCovered) {
                res++;
            }
        }
        return res;
    }
};