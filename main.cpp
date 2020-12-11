#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

//快速排序经典写法
void quick_sort(vector<int> &nums, int left, int right) {
    if(left + 1 >= right) {
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

//归并排序经典写法
void merge_sort(vector<int> &nums, int left, int right, vector<int> &temp) {
    if(left + 1 >= right) {
        return;
    }
    int middle = left + (right - left) / 2;
    merge_sort(nums, left, middle, temp);
    merge_sort(nums, middle, right, temp);
    int left_start = left;
    int right_start = middle;
    int i = left;
    while (left_start < middle || right_start < right)
    {
        if(right_start >= right || (left_start < middle 
        && nums[left_start] <= nums[right_start])) {
            temp[i++] = nums[left_start++];
        } else {
            temp[i++] = nums[right_start++];
        }
    }
    for(int i = left; i < right; ++i) {
        nums[i] = temp[i];
    }
}

//插入排序经典写法
using std::swap;
void insert_sort(vector<int> &nums, int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
            swap(nums[j], nums[j - 1]);
        }
    }
}

//冒泡排序经典写法
void bubble_sort(vector<int> &nums, int n) {
    for(int i = 1; i < n; ++i) {
        int swap_flag = false;
        for(int j = 1; j < n - i + 1; ++j) {
            if(nums[j] < nums[j - 1]) {
                swap(nums[j], nums[j - 1]);
                swap_flag = true;
            }
        }
        if(!swap_flag) {
            break;
        }
    }
}

int main()
{
    vector<int> nums = {1, 3, 5, 7, 2, 6, 4, 8, 9, 2, 8, 
    7, 6, 0, 3, 5, 9, 4, 1, 0};
    vector<int>temp(nums.size());
    bubble_sort(nums, nums.size());
    for(const auto &element : nums) {
        cout << element << " ";
    }
    cout << endl;
}