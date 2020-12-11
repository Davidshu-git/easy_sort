#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void quick_sort(vector<int> &nums, int left, int right) {
    if(left == right) {
        return;
    }
    int first = left;
    int last = right - 1;
    int key = nums[first];
    while (first < last)
    {
        while(first < last && nums[last] >= key) {
            --last;
        }
        nums[first] = nums[last];
        while (first < last && nums[first] <= key)
        {
            ++first;
        }
        nums[last] = nums[first];
    }
    nums[first] = key;
    quick_sort(nums, left, first);
    quick_sort(nums, first + 1, right);
}

int main()
{
    vector<int> nums = {1, 3, 5, 7, 2, 6, 4, 8, 9, 2, 8, 
    7, 6, 0, 3, 5, 9, 4, 1, 0};
    quick_sort(nums, 0, nums.size());
    for(const auto &element : nums) {
        cout << element << " ";
    }
    cout << endl;
}