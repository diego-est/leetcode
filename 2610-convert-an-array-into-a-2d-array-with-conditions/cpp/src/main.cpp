#include <iostream>
#include <vector>
#include <unordered_map>

auto findMatrix(std::vector<int>& nums) -> std::vector<std::vector<int>>
{
	auto max_count = 0;
	auto counts = std::unordered_map<int, int>();
	for (auto const& num : nums)
		max_count = std::max(max_count, ++counts[num]);

	auto arr = std::vector<std::vector<int>>(max_count);
	for (auto & [num, count] : counts)
		while (count--) arr[count].push_back(num);

	return arr;
}

auto main() -> int
{
	auto nums1 = std::vector{1,3,4,1,2,3,1};
	auto const ret1 = findMatrix(nums1);
	for (auto const& row : ret1) {
		std::cout << "- ";
		for (auto ch = std::string(); auto const& num : row) {
			std::cout << ch << num, ch = ", ";
		}
		std::cout << std::endl;
	}

	auto nums2 = std::vector{ 1, 2, 3, 4 };
	auto const ret2 = findMatrix(nums2);
	for (auto const& row : ret2) {
		std::cout << "- ";
		for (auto ch = std::string(); auto const& num : row) {
			std::cout << ch << num, ch = ", ";
		}
		std::cout << std::endl;
	}
	return 0;
}

