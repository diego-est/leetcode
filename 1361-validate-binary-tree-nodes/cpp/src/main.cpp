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

typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;

auto validateBinaryTreeNodes(int n, std::vector<int>& leftChild, std::vector<int>& rightChild)
{
	auto nodes = vii();
	/* find the parent of each node */
	for (size_t i = 0; i < n; i++) {
		nodes.push_back({ leftChild[i], rightChild[i] });
	}

	/* a valid tree:
	* only 1 parent per node
	* only 1 node with no parent
	*/
	return false;
}

auto main() -> int
{
	auto c1l = std::vector{ 1, -1, 3, -1 };
	auto c1r = std::vector{ 2, -1, -1, -1 };
	auto c1n = 4;

	std::cout << validateBinaryTreeNodes(c1n, c1l, c1r) << std::endl;
	return 0;
}

