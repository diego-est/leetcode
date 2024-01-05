#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>
using namespace std::string_literals;

bool makeEqual(std::vector<std::string>& words)
{
	auto const size = words.size();
	if (size == 1llu)
		return true;

	auto const char_count = std::accumulate(
	    words.cbegin(), words.cend(), 0llu,
	    [](auto const& acc, auto const& x) { return acc + x.length; });

	if (char_count % size != 0)
		return false;

	auto alphabet = std::array<size_t, 26>();
	for (auto const& word : words)
		for (auto const& character : word)
			alphabet[character - 'a'] += 1;

	return std::ranges::all_of(alphabet,
				   [size](auto x) { return x % size == 0; });
}

[[nodiscard, gnu::const]] auto main() -> int
{
	auto ex1 = std::vector<std::string>{"abc"s, "aabc"s, "bc"s};
	auto ex2 = std::vector<std::string>{"ab"s, "a"s};
	auto ex3 = std::vector<std::string>{"a"s, "b"s};
	auto ex4 = std::vector<std::string>{"b"s};
	auto ex5 = std::vector<std::string>{"a"s, "a"s, "a"s};
	auto ex6 = std::vector<std::string>{"bc"s, "de"s};
	auto ex7 = std::vector<std::string>{"aab"s, "b"s};
	auto ex8 = std::vector<std::string>{
	    "caaaaa"s,	  "aaaaaaaaa"s, "a"s,  "bbb"s,
	    "bbbbbbbbb"s, "bbb"s,	"cc"s, "cccccccccccc"s,
	    "ccccccc"s,	  "ccccccc"s,	"cc"s, "cccc"s,
	    "c"s,	  "cccccccc"s,	"c"s};

	std::cout << "True\n ";
	std::cout << std::boolalpha << makeEqual(ex1) << std::endl;

	std::cout << "False\n ";
	std::cout << std::boolalpha << makeEqual(ex2) << std::endl;

	std::cout << "False\n ";
	std::cout << std::boolalpha << makeEqual(ex3) << std::endl;

	std::cout << "True\n ";
	std::cout << std::boolalpha << makeEqual(ex4) << std::endl;

	std::cout << "True\n ";
	std::cout << std::boolalpha << makeEqual(ex5) << std::endl;

	std::cout << "False\n ";
	std::cout << std::boolalpha << makeEqual(ex6) << std::endl;

	std::cout << "True\n ";
	std::cout << std::boolalpha << makeEqual(ex7) << std::endl;

	for (auto const& word : ex8)
		std::cout << word << ' ';
	std::cout << std::endl;
	std::cout << "True\n ";
	std::cout << std::boolalpha << makeEqual(ex8) << std::endl;

	for (auto const& word : ex8)
		std::cout << word << ' ';
	std::cout << std::endl;
	return 0;
}
