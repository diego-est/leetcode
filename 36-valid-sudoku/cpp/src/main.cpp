#include <iostream>
#include <vector>
#include <unordered_set>

auto isValidSudoku(std::vector<std::vector<char>>& board) -> bool
{
	auto set = std::unordered_set<char>();
	/* rows */
	for (auto const& row : board) {
		for (auto const& tile : row) {
			if (tile != '.' && set.contains(tile)) return false;
			set.insert(tile);
		}
		set.clear();
	}

	/* columns */
	for (auto idx = 0llu; idx < 9; ++idx) {
		for (auto const& row : board) {
			if (row[idx] != '.' && set.contains(row[idx])) return false;
			set.insert(row[idx]);
		}
		set.clear();
	}

	/* boxes */
	for (auto idx = 0llu; idx < 9; idx += 3) {
		for (auto jdx = 0llu; jdx < 9; jdx += 3) {
			for (auto kdx = 0llu; kdx < 3; ++kdx) {
				for (auto ldx = 0llu; ldx < 3; ++ldx) {
					auto const item = board[kdx + idx][ldx + jdx];
					std::cout << item << ' ';
					if (item != '.' && set.contains(item)) {
						return false;
					}
					set.insert(item);
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
			set.clear();
		}
		std::cout << std::endl;
	}
	/*
	for (auto idx = 0llu; idx < 9; idx += 3) {
		for (auto jdx = 0llu; jdx < 3; ++jdx) {
			if (board[idx][jdx] != '.' && set.contains(board[idx][jdx])) return false;
			set.insert(board[idx][jdx]);
		}
		for (auto jdx = 3llu; jdx < 3; ++jdx) {
			if (board[idx + 1][jdx] != '.' && set.contains(board[idx + 1][jdx])) return false;
			set.insert(board[idx + 1][jdx]);
		}
		for (auto jdx = 6llu; jdx < 3; ++jdx) {
			if (board[idx + 2][jdx] != '.' && set.contains(board[idx + 2][jdx])) return false;
			set.insert(board[idx + 2][jdx]);
		}
		set.clear();
	}
      */

	return true;
}

auto main() -> int
{
	auto ex1 = std::vector{std::vector
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}};

	auto ex2 = std::vector{std::vector
		{'.','1','.','.','.','.','.','.','1'},
		{'.','1','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','1'}};

	auto ex3 = std::vector{std::vector
		{'.','.','4','.','.','.','6','3','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'5','.','.','.','.','.','.','9','.'},
		{'.','.','.','5','6','.','.','.','.'},
		{'4','.','3','.','.','.','.','.','1'},
		{'.','.','.','7','.','.','.','.','.'},
		{'.','.','.','5','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'}};
	auto ex4 = std::vector{std::vector
		{'.','.','.','.','5','.','.','1','.'},
		{'.','4','.','3','.','.','.','.','.'},
		{'.','.','.','.','.','3','.','.','1'},
		{'8','.','.','.','.','.','.','2','.'},
		{'.','.','2','.','7','.','.','.','.'},
		{'.','1','5','.','.','.','.','.','.'},
		{'.','.','.','.','.','2','.','.','.'},
		{'.','2','.','9','.','.','.','.','.'},
		{'.','.','4','.','.','.','.','.','.'}};
//	std::cout << std::boolalpha << isValidSudoku(ex1) << std::endl;
//	std::cout << std::boolalpha << isValidSudoku(ex2) << std::endl;
//	std::cout << std::boolalpha << isValidSudoku(ex3) << std::endl;
	std::cout << std::boolalpha << isValidSudoku(ex4) << std::endl;
	return 0;
}

