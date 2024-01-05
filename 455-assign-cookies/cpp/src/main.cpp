#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <queue>
#include <algorithm>
#include <ranges>

auto findContentChildren(std::vector<int>& g, std::vector<int>& s) -> int
{
	auto counter = 0;
	std::ranges::sort(g);
	std::ranges::sort(s);

	auto sit = s.cbegin();
	for (auto const& greed : g) {
		while (sit != s.cend() && *sit < greed) ++sit;
		if (sit != s.cend() && *sit >= greed) ++counter, ++sit;
	}
	return counter;
}

auto main() -> int
{
	auto ex1g = std::vector{ 1, 2, 3 };
	auto ex1s = std::vector{ 1, 1 };

	auto ex2g = std::vector{ 1, 2 };
	auto ex2s = std::vector{ 1, 2, 3 };

	auto ex3g = std::vector{ 10, 9, 8, 7 };
	auto ex3s = std::vector{ 5, 6, 7, 8 };

	std::cout << findContentChildren(ex1g, ex1s) << std::endl;
	std::cout << findContentChildren(ex2g, ex2s) << std::endl;
	std::cout << findContentChildren(ex3g, ex3s) << std::endl;
	return 0;
}

