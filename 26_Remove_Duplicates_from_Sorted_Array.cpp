//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <iostream>
#include <vector>

using namespace std;

void PrintVector(const vector<int> &v) {
    cout << '{';
    for (const auto &item : v) {
        cout << item << ',';
    }
    cout << '}' << endl;
    return;
}

int removeDuplicates(vector<int> &nums) {
    int Start = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            nums[Start] = nums[i];
            Start++;
        }
    }
    if (nums.size() > 0){
        nums.resize(Start);
    }
    return nums.size();
}

int main() {
    {
        vector<int> nums = {1, 1, 2};
        PrintVector(nums);
        cout << removeDuplicates(nums) << endl;
        PrintVector(nums);
    }
    {
        vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        PrintVector(nums);
        cout << removeDuplicates(nums) << endl;
        PrintVector(nums);
    }
    {
        vector<int> nums = {};
        PrintVector(nums);
        cout << removeDuplicates(nums) << endl;
        PrintVector(nums);
    }
    return 0;
}
