#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

auto numberOfBeams(std::vector<std::string>& bank) -> int
{
	return std::accumulate(
	    bank.cbegin(), bank.cend(), 0,
	    [prev = 0, curr = 0](auto const& acc, auto const& row) mutable {
		    prev = curr;
		    curr = std::ranges::count(row, '1');
		    if (curr == 0)
			    return acc;


		    return acc + (curr * prev);
	    });
}

auto main() -> int
{
	auto bank1 =
	    std::vector<std::string>{"011001", "000000", "010100", "001000"};
	auto bank2 = std::vector<std::string>{"000", "111", "000"};
	std::cout << numberOfBeams(bank1) << std::endl;
	std::cout << numberOfBeams(bank2) << std::endl;
	return 0;
}
