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

std::vector<int> sumZero(int n);

auto main() -> int
{
	for (const auto & n : sumZero(1))
		std::cout << n << std::endl;
	std::cout << std::endl;
	for (const auto & n : sumZero(2))
		std::cout << n << std::endl;
	std::cout << std::endl;
	for (const auto & n : sumZero(3))
		std::cout << n << std::endl;
	std::cout << std::endl;
	for (const auto & n : sumZero(4))
		std::cout << n << std::endl;
	std::cout << std::endl;
	for (const auto & n : sumZero(5))
		std::cout << n << std::endl;
	std::cout << std::endl;
	return 0;
}

std::vector<int> sumZero(int n)
{
	auto a = std::vector<int>(n, 0);
	if (n & 1)
		a[0] = 0, n--;
	n /= 2;
	for (size_t i = 0; i < a.size() && n; i += 2) {
		a[i] = n;
		a[i+1] = n * -1;
		n--;
	}

	return a;
}
