#include <iostream>
#include <algorithm>
#include <vector>
#include <format>
#include <cmath>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	auto it1 = nums1.cbegin();
	auto it2 = nums2.cbegin();
	auto const s3 = nums1.size() + nums2.size();
	auto nums3 = std::vector<int>(s3);
	auto finished1 = false;
	auto finished2 = false;
	for (auto& n : nums3) {
		if (finished1) {
			n = *it2++;
		} else if (finished2) {
			n = *it1++;
		} else if (*it1 < *it2) {
			n = *it1++;
			if (it1 == nums1.cend()) finished1 = true;
		} else {
			n = *it2++;
			if (it2 == nums2.cend()) finished2 = true;
		}
	}

	if (s3 % 2 != 0) return double(nums3[(s3 - 1) / 2]);
	else {
		auto const i1 = s3 / 2;
		auto const i2 = i1 - 1;
		std::cout << std::format("{} {} {}\n", s3, i1, i2);
		return double(nums3[i1] + nums3[i2]) / 2.0;
	}
}
auto main() -> int
{
	auto nums1 = std::vector{ 1, 2 };
	auto nums2 = std::vector{ 3, 4 };

	std::cout << std::format("{}\n", findMedianSortedArrays(nums1, nums2));
	return 0;
}

