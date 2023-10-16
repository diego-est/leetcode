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
#include <string>

auto main() -> int
{
	std::cout << "Hello world!\n";
	return 0;
}

class Solution {
public:
	std::vector<int> lastVisitedIntegers(std::vector<std::string>& words) {
		auto solution = std::vector<int>();
		auto nums = std::vector<int>();
		auto rb = nums.rbegin();
		size_t k = 0;
		for (const auto& word : words) {
			rb = nums.rbegin();
			if (word == "prev")
				solution.push_back(k >= nums.size() ? -1 : *(rb + k)),
					k++;
			else
				nums.push_back(stoi(word)), k = 0;
		}
		return solution;
	}
};
