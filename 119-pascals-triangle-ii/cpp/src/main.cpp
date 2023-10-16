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
#include <numeric>

auto main() -> int
{
	std::cout << "Hello world!\n";
	return 0;
}

class Solution {
public:
	std::vector<int> getRow(int rowIndex) {
		auto a = std::vector{ 1 };
		while (rowIndex--) {
			std::adjacent_difference(a.begin(), a.end(), a.begin(),
			    [](auto x, auto y) { return x + y; });
			a.push_back(1);
		}
		return a;
	}
};
