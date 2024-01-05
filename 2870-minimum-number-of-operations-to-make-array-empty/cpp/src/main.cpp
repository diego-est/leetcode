#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <numeric>
#include <algorithm>

int minOperations(std::vector<int>& nums)
{
	auto mp = std::unordered_map<int, int>();
	for (auto const& num : nums) ++mp[num];

	return int(std::accumulate(mp.cbegin(), mp.cend(), 0.0,
			[b = false](auto const& acc, auto const& p) mutable {
			    b |= p.second == 1;
			    // if (p.second == 1) b = true;

			    if (not b)
			    return acc + ceil(p.second / 3.0);
			    else
			    return -1.0;
			}
		));
	/*
	
	auto counter = 0;
	for (auto const& [_, c] : mp) {
		if (c == 1) return -1;

		counter += ceil(c / 3.0);
	}
	return counter;
	*/
}


auto main() -> int
{
	auto nums1 = std::vector<int>{ 2,3,3,2,2,4,2,3,4};
	auto nums2 = std::vector<int>{ 2,1,2,2,3,3 };
	auto nums3 = std::vector<int>{ 2, 2, 2, 2, 2, 2 };
	auto nums4 = std::vector<int>{ };
	auto nums5 = std::vector<int>{ 2, 2, 3 };
	auto nums6 = std::vector<int>{152,152,152,152,152,152,152,152,152,152,152,152,215,152,152,152,152,152,152,152,152,152,152,152,152,152,152,152,152,152,152,114,152,152,152,152,152,152,152,152,152,152,152,152,152,152,152,152,152,152,215,152,152,152,152,152,152,152,152,114,152,152,152,152,152,114,152,152,152,114,152,152,152,114,152,152,152,114,152,152,152,152,152,215};
	auto nums7 = std::vector<int>{ 14,12,14,14,12,14,14,12,12,12,12,14,14,12,14,14,14,12,12 };
	auto nums8 = std::vector<int>{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
	auto nums9 = std::vector<int>{ 2, 2, 2, 2, 2, 2, 2, 2, 2 };
	std::cout << "Nums1: " << minOperations(nums1) << std::endl;
	std::cout << "Nums2: " << minOperations(nums2) << std::endl;
	std::cout << "Nums3: " << minOperations(nums3) << std::endl;
	std::cout << "Nums4: " << minOperations(nums4) << std::endl;
	std::cout << "Nums5: " << minOperations(nums5) << std::endl;
	std::cout << "Nums7: " << minOperations(nums7) << std::endl;
	std::cout << "Nums6: " << minOperations(nums6) << std::endl;
	std::cout << "Nums8: " << minOperations(nums8) << std::endl;
	std::cout << "Nums9: " << minOperations(nums9) << std::endl;

	auto mp = std::unordered_map<int, int>();
	for (auto const& num : nums7) {
		mp[num] += 1;
	}

	for (auto const& pair : mp) {
		std::cout << "(" << pair.first << ", " << pair.second << ")\n";
	}

	return 0;
}
