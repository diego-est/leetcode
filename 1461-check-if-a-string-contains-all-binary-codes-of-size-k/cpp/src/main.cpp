/* ========================================================================
 *
 *     Filename:  
 *  Description:  
 *       Author:  
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <iostream>
#include <string>
#include <cassert>
#include <unordered_set>
#include <cmath>

auto hasAllCodes(std::string s, int k)
{
	if (s.size() < k)
		return false;

	auto mp = std::unordered_set<std::string>();

	for (auto it = 0; it <= s.size() - k; ++it)
		mp.insert(s.substr(it, k));

	for (const auto& e : mp)
		std::cout << e << " ";
	std::cout << std::endl;

	return mp.size() == std::pow(2, k);
}

auto main() -> int
{
	auto s1 = std::string("00110110");
	auto k1 = 2;
	assert(hasAllCodes(s1, k1) == true);

	std::cout << "Passed 1.\n";

	auto s2 = std::string("0110");
	auto k2 = 1;
	assert(hasAllCodes(s2, k2) == true);
	std::cout << "Passed 2.\n";

	auto s3 = std::string("0110");
	auto k3 = 2;
	assert(hasAllCodes(s3, k3) == false);
	std::cout << "Passed 3.\n";

	auto s4 = std::string("00000000010011101");
	auto k4 = 4;
	assert(hasAllCodes(s4, k4) == false);
	std::cout << "Passed 4.\n";

	auto s5 = std::string("00110");
	auto k5 = 2;
	assert(hasAllCodes(s5, k5) == true);
	std::cout << "Passed 5.\n";

	auto s6 = std::string("00000000001011100");
	auto k6 = 3;
	assert(hasAllCodes(s6, k6) == true);
	std::cout << "Passed 6.\n";

	auto s7 = std::string("01");
	auto k7 = 1;
	assert(hasAllCodes(s7, k7) == false);
	std::cout << "Passed 7.\n";

	return 0;
}

