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
#include <cassert>
#include <algorithm>
#include <deque>

auto getWinner(std::vector<int>& arr, int k)  -> int
{
		auto max = *std::max_element(arr.cbegin(), arr.cend());
		if (k > arr.size())
			return max;
	
		auto d = std::deque(arr.begin(), arr.end());
	
		auto wins_left = k;
		while (wins_left) {
			std::cout << "In loop, and max: " << max << std::endl;
			for (const auto& e : d)
				std::cout << e << ' ';
			std::cout << std::endl;
			if (arr[0] == max)
				wins_left = 0;
			else if (d[0] > d[1]) {
				--wins_left;
				const auto a = d.front();
				d.pop_front();
				const auto b = d.front();
				d.pop_front();
				d.push_front(a);
				d.push_back(b);
			}
			else {
				wins_left = k - 1;
				auto a = d.front();
				d.pop_front();
				d.push_back(a);
			}
		}
	
		std::cout << "Winner: " << d[0] << std::endl;
	
		return d[0];
}

auto get_winner(vector<int>& arr, int k) {
	auto cur = A[0];
	auto win = 0;

	for (const auto& e : arr) {
		if (e > cur)
			cur = e, win = 0;

		if (++win == k) break;
	}

    return cur;
}

auto main() -> int
{
	auto arr1 = std::vector<int>{ 2, 1, 3, 5, 4, 6, 7 };
	auto k1 = 2;
	assert(getWinner(arr1, k1) == 5);

	auto arr2 = std::vector<int>{ 3, 2, 1 };
	auto k2 = 10;
	assert(getWinner(arr2, k2) == 3);


	auto arr3 = std::vector<int>{ 1, 11, 22, 33, 44, 55, 66, 77, 88, 99 };
	auto k3 = 1000000000;
	assert(getWinner(arr3, k3) == 99);

	return 0;
}

