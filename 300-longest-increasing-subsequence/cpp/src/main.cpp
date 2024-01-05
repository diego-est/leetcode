#include <iostream>
#include <vector>
#include <algorithm>
#include <format>

int lengthOfLIS(std::vector<int>& nums)
{
	auto counter = 0;
	auto max = 0;
	for (auto idx = 0llu; auto const& n : nums) {
		for (auto jdx = idx; jdx < nums.size(); ++jdx) {
			if (n <)
		}
		++idx;
	}
	return counter;
}

auto main() -> int
{
	auto nums1 = std::vector{10,9,2,5,3,7,101,18};
	auto nums2 = std::vector{0,1,0,3,2,3};
	auto nums3 = std::vector{7,7,7,7,7,7,7};
	auto nums4 = std::vector{ 1, 10, 2, 3, 4, 20, 5 };

	std::cout << std::format("nums1: {}\n", lengthOfLIS(nums1));
	std::cout << std::format("nums2: {}\n", lengthOfLIS(nums2));
	std::cout << std::format("nums3: {}\n", lengthOfLIS(nums3));
	return 0;
}

