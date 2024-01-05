#include <iostream>
#include <unordered_map>

static auto memo = std::unordered_map<int, int>();

auto climbStairs(int n) -> int
{
	if (memo.contains(n)) return memo[n];
        if (n <= 2) return n;

        memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return memo[n];
}

auto main() -> int
{
	std::cout << climbStairs(2) << std::endl;
	std::cout << climbStairs(3) << std::endl;
	std::cout << climbStairs(45) << std::endl;
}
