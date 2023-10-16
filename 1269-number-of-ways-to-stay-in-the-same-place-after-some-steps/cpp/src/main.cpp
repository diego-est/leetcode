/* ========================================================================
 *
 *     Filename:  
 *  Description:  
 *       Author:  
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <iostream>
#include <vector>

auto main() -> int
{
	std::cout << "Hello world!\n";
	return 0;
}

class Solution {
public:
	std::vector<std::vector<int>> memo;
	int arrLen;
	int mod = 1e9 + 7;
	int numWays(int steps, int arrLen) {
		arrLen = std::min(steps / 2 + 1, arrLen);
		this->arrLen = arrLen;
		memo = std::vector(arrLen, std::vector(steps + 1, -1));
		return dp(0, steps);
	}
	auto dp(int curr, int remain) -> int
	{
		if (remain == 0)
			return curr == 0 ? 1 : 0;

		if (memo[curr][remain] != -1)
			return memo[curr][remain];

		int ans = dp(curr, remain - 1);
		if (curr > 0)
			ans = (ans + dp(curr - 1, remain - 1)) % mod;
		if (curr < arrLen - 1)
			ans = (ans + dp(curr + 1, remain - 1)) % mod;

		memo[curr][remain] = ans;
		return ans;
	}
};
