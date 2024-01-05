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

auto removeDuplicates(std::vector<int>& nums) {
        auto j = 1;
        for(size_t i = 1; i < nums.size(); i++)
            if(nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                j++;
            }

        return j;
}

auto main() -> int
{
	std::cout << "Hello world!\n";
	return 0;
}

