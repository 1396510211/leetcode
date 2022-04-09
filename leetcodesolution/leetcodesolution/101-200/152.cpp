#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_ = nums[0];
        int max_ = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmp1 = min_ * nums[i];
            int tmp2 = max_ * nums[i];
            min_ = min(nums[i], min(tmp2, tmp1));
            max_ = max(nums[i], max(tmp2, tmp1));
            res = max(max_, res);
        }
        return res;
    }
};