#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto cmp = [&](const int a, const int b) {
            return getMapping(a, mapping) < getMapping(b, mapping);
        };
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
    int getMapping(int num, vector<int>& mapping) {
        if (num == 0) {
            return mapping[0];
        }
        vector<int> res;
        while (num)
        {
            res.push_back(num % 10);
            num /= 10;
        }
        reverse(res.begin(), res.end());
        string s;
        for (const auto& bit : res) {
            s += to_string(mapping[bit]);
        }
        return stoi(s);
    }
};