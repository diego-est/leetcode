#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

auto countBits(int n) -> vector<int>
{
	auto x = 0;
	auto a = vector<int>(n + 1, 0);
	for (auto x = 0; auto& k : a)
		k = bitset<32>(x++).count();

	return a;
}

auto main() -> int
{
	for (auto const& n : countBits(5))
		std::cout << n << ' ';
	return 0;
}

