#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <optional>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

int maxLengthBetweenEqualCharacters2(string s) {
	return std::accumulate(s.cbegin(), s.cend(), -1, [mp = array<int, 26>(), idx = 0](auto acc, auto const ch) mutable {
		if (mp[ch - 'a'] == 0)
			mp[ch - 'a'] = idx + 1;
		acc = max(acc, idx - mp[ch - 'a']);
		++idx;
		return acc;
	});
}

auto maxLengthBetweenEqualCharacters(string s) -> int
{
	auto mp = array<optional<pair<int, optional<int>>>, 27>();

	for (auto idx = 0; auto const& ch : s) {
		mp[ch - 'a'] = mp[ch - 'a']
				   ? make_pair(mp[ch - 'a'].value().first,
					       optional<int>{idx})
				   : make_pair(idx, nullopt);
		++idx;
	}

	return std::accumulate(
		   mp.cbegin(), mp.cend(), -1,
		   [](auto acc, auto const& char_opt) {
			   if (char_opt) {
				   auto const pair = char_opt.value();
				   auto const difference =
				       pair.second.value_or(pair.first) -
				       pair.first;
				   acc = difference > acc ? difference : acc;
			   }
			   return acc;
		   }) -
	       1;
}

auto main() -> int
{
	std::cout << maxLengthBetweenEqualCharacters2("aa") << "\t\t 0"
		  << std::endl;
	std::cout << maxLengthBetweenEqualCharacters2("abca") << "\t\t 2"
		  << std::endl;
	std::cout << maxLengthBetweenEqualCharacters2("cbzxy") << "\t-1"
		  << std::endl;
	std::cout << maxLengthBetweenEqualCharacters2("abac") << "\t\t 1"
		  << std::endl;
	std::cout << maxLengthBetweenEqualCharacters2("ab") << "\t\t-1"
		  << std::endl;
	std::cout << maxLengthBetweenEqualCharacters2("a") << "\t\t-1"
		  << std::endl;
	std::cout << maxLengthBetweenEqualCharacters2("cabbac") << "\t 4"
		  << std::endl;
	std::cout << maxLengthBetweenEqualCharacters2("cabad") << "\t 1"
		  << std::endl;
	std::cout << maxLengthBetweenEqualCharacters2(
			 "mgntdygtxrvxjnwksqhxuxtrv")
		  << "\t18" << std::endl;
	return 0;
}
