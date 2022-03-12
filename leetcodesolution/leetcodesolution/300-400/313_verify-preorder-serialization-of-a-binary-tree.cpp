#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
	bool isValidSerialization(string preorder)
	{
		vector<string> vec;
		stringstream ss(preorder);
		string s;
		while (getline(ss, s, ',')) {
			vec.push_back(s);
			size_t size = vec.size();
			while (size >= 3 && vec[size - 2] == "#" && vec[size - 3] != "#" && s == "#") {
				vec.pop_back();
				vec.pop_back();
				vec.pop_back();
				vec.push_back("#");
				size = vec.size();
			}
		}
		return vec.size() == 1 && vec.back() == "#";
	}
};