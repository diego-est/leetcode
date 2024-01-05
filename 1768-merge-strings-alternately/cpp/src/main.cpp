#include <iostream>
#include <string>
using namespace std;

string mergeAlternately(string word1, string word2) {
	auto a = string(word1.length() + word2.length(), char());
	auto a_it = a.begin();
	auto parity = true;
	auto it1 = word1.cbegin();
	auto it2 = word2.cbegin();
	while (a_it != a.end()) {
		*a_it = parity ? *it1++ : *it2++;
		if (it1 == word1.cend()) parity = false;
		else if (it2 == word2.cend()) parity = true;
		else parity = not parity;
		++a_it;
	}
	return a;
}

auto main() -> int
{
	std::cout << mergeAlternately("abc", "pqr") << std::endl;
	std::cout << mergeAlternately("ab", "pqrs") << std::endl;
	return 0;
}

