#include <iostream>
#include <vector>
class Sort{
public:
	void BubbleSort(std::vector<int>& nums);
};

void Sort::BubbleSort(std::vector<int>& nums) {
	int n = nums.size();
	//sort from small to big
	for (int i = 0; i < n - 1; i++) {//scan n-1
		for (int j = 0; j < n - i - 1; j++) {
			if (nums[j] > nums[j + 1]) {
				std::swap(nums[j], nums[j + 1]);
			}
		}
	}
}

int main()
{
	std::vector<int> nums = { 5,8,3,9,1 };
	Sort mysort;
	mysort.BubbleSort(nums);
	for (int i = 0; i < nums.size(); i++) {
		std::cout << nums[i] << " ";
	}
}

