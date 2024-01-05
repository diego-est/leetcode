/* ========================================================================
 *
 *     Filename:  
 *  Description:  
 *       Author:  
 *      Version:  0.0.1
 *
 * ======================================================================== */
#include <iostream>
#include <array>
struct Stack {
	std::array<int, 30000> stack;
	size_t size;

	auto push(int val) -> void
	{
		stack[size] = val;
		size++;
	}

	auto pop() -> void
	{
		stack[size] = 0;
		size--;
	}

	auto top() -> int
	{
		return stack[size];
	}

	[[nodiscard]] auto empty() -> bool
	{
		return size == 0;
	}
};

class MinStack {
	Stack stack;
	Stack mins;

public:
	MinStack()
	{
	}

	void push(int val) {
		if (mins.val <= mins.top())
			stack
	}

	void pop() {
	}

	int top() {
	}

	int getMin() {
	}
};

auto main() -> int
{
	auto a = MinStack();
	a.push(2);
	a.push(0);
	a.push(3);
	a.push(0);

	std::cout << a.getMin() << std::endl;

	a.pop();
	std::cout << a.getMin() << std::endl;

	a.pop();
	std::cout << a.getMin() << std::endl;

	a.pop();
	std::cout << a.getMin() << std::endl;

	/*
	std::cout << a.top() << std::endl;
	std::cout << a.top() << std::endl;
	*/

	return 0;
}

