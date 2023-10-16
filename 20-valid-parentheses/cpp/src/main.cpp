/* ========================================================================
 *
 *     Filename:  
 *  Description:  
 *       Author:  
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <iostream>
#include <string>
#include <stack>

auto main() -> int
{
	std::cout << "Hello world!\n";
	return 0;
}

class Solution {
public:
    bool isValid(std::string s) {
	auto st = std::stack<char>();

	for (const auto& ch : s) {
		char check = '\0';
		switch (ch) {
			case '(':
			case '{':
			case '[':
				st.push(ch);
				continue;
			case ')':
				check = '(';
				break;
			case '}':
				check = '{';
				break;
			case ']':
				check = '[';
				break;
			default: continue;
		}
		if (not st.empty()) {
			if (st.top() == check)
				st.pop();
			else
				return false;
		} else {
			return false;
		}
			

	}

	return st.empty();
    }
};
