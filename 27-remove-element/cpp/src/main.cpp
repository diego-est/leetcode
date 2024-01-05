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

auto removeElement(std::vector<int>& nums, int val) -> int{
	auto insert = nums.begin();
	auto ptr = insert;
	auto k = 0;

	while (ptr != nums.end()) {
		*insert = (*ptr != val) ? ++insert, ++k, *ptr : *insert;
		++ptr;
	}

	return k;
}

auto main() -> int
{
	auto n1 = std::vector{ 3, 2, 2, 3 };
	auto v1 = 3;

	std::cout << removeElement(n1, v1) << std::endl;

	for (const auto &e : n1)
		std::cout << e << ' ';
	std::cout << "\n";

	auto n2 = std::vector{ 0, 1, 2, 2, 3, 0, 4, 2 };
	auto v2 = 2;

	std::cout << removeElement(n2, v2) << std::endl;

	for (const auto &e : n2)
		std::cout << e << ' ';
	std::cout << "\n";
	return 0;
}

