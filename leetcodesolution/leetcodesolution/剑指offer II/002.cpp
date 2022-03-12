#include "../pch.h"

#include <bitset>

class Solution {
public:
	string addBinary(string a, string b)
	{
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		string res;
		char carry = '0';
		size_t i;
		for (i = 0; i < a.size() && i < b.size(); i++) {
			int tmp = (a[i] - '0' + b[i] - '0' + carry - '0');
			res.push_back(((tmp % 2) + '0'));
			carry = (tmp / 2) + '0';
		}
		if (i < a.size()) {
			if (carry == '1') {
				string next = a.substr(i, a.size() - i);
				reverse(next.begin(), next.end());
				string t = addBinary("1", next);
				reverse(t.begin(), t.end());
				res += t;
				carry = '0';
			}
			else {
				res.append(a.substr(i, a.size() - i));
			}
		}
		if (i < b.size()) {
			if (carry == '1') {
				string next = b.substr(i, b.size() - i);
				reverse(next.begin(), next.end());
				string t = addBinary("1", next);
				reverse(t.begin(), t.end());
				res += t;
				carry = '0';
			}
			else {
				res.append(b.substr(i, b.size() - i));
			}
		}
		if (carry == '1') {
			res.push_back(carry);
		}
		reverse(res.begin(), res.end());
		return res;
	}
};