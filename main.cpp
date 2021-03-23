#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

//快速排序经典写法：时间复杂度(nlogn->n^2，平均nlogn)、空间复杂度(logn->n，平均logn)、不稳定
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

//归并排序经典写法：时间复杂度(nlogn)、空间复杂度(n)、稳定
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

//插入排序经典写法：时间复杂度(n->n^2，平均n^2)、空间复杂度(1)、稳定
using std::swap;
void insert_sort(vector<int> &nums, int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
            swap(nums[j], nums[j - 1]);
        }
    }
}

//冒泡排序经典写法：时间复杂度(n->n^2，平均n^2)、空间复杂度(1)、稳定
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

//选择排序经典写法：时间复杂度(n^2)、空间复杂度(1)、不稳定
void selection_sort(vector<int> &nums, int n) {
    int selection_index = 0;
    for (int i = 0; i < n - 1; ++i) {
       selection_index = i;
       for(int j = i + 1; j < n; ++j) {
           if(nums[j] < nums[selection_index]) {
               selection_index = j;
           }
       } 
       swap(nums[i], nums[selection_index]);
    }
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