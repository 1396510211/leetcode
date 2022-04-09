#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		const int size = gas.size();
		for (int i = 0; i < size;) {
			int sumOfGas = 0;
			int sumOfCost = 0;
			int cnt = 0;
			while (cnt < size) {
				int j = (cnt + i) % size;
				sumOfGas += gas[j];
				sumOfCost += cost[j];
				if (sumOfCost > sumOfGas) {
					break;
				}
				cnt++;
			}
			if (cnt == size) {
				return i;
			}
			else {
				i = i + cnt + 1;
			}
		}
		return -1;
	}
};