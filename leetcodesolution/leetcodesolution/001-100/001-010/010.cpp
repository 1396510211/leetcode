#include "../../pch.h"

class Solution {
public:
	bool isMatch(const string& s, int sidx, const string& p, int pidx) {
		if (pidx == p.size()) {
			return sidx == s.size();
		}
		if ((pidx + 1 < p.size()) && p[pidx + 1] == '*') {
			// s = "aab" p = "c*a*b" 用* 匹配前面的字母0次 相当于抹掉
			if (isMatch(s, sidx, p, pidx + 2)) {
				return true;
			}
			if (sidx < s.size() && p[pidx] == '.' || s[sidx] == p[pidx]) {
				return isMatch(s, sidx + 1, p, pidx);
			}
		}
		else if (sidx < s.size() && (p[pidx] == '.') || s[sidx] == p[pidx]) {
			return isMatch(s, sidx + 1, p, pidx + 1);
		}
		return false;
    }
	bool isMatch(string s, string p) {
		return isMatch(s, 0, p, 0);
    }
};
