#include <iostream>
#include <vector>
using namespace std;

auto reversePairs(vector<int>& nums) -> int
{
	auto counter = 0;

	for (auto i = nums.cbegin(); i != nums.cend() - 1; ++i)
		for (auto j = i + 1; j != nums.cend(); ++j)
			if (*i > 2ll * (long long)*j) ++counter;

	return counter;
}

auto main() -> int
{
	auto nums1 = std::vector{ 1, 3, 2, 3, 1 };
	auto nums2 = std::vector{ 2, 4, 3, 5, 1 };
	auto nums3 = std::vector{ 2147483647,2147483647,2147483647,2147483647,2147483647,2147483647 };

	std::cout << reversePairs(nums1) << std::endl;
	std::cout << reversePairs(nums2) << std::endl;
	std::cout << reversePairs(nums3) << std::endl;
	return 0;
}

