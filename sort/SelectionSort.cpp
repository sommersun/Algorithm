#include <iostream>
#include <vector>
class Sort{
public:
	void SelectionSort(std::vector<int>& nums);
};
void Sort::SelectionSort(std::vector<int>& nums) 
{	//sort from small to big
	for (int i = 0; i < nums.size()-1;i++) {//n-1 selection
		int min = nums[i];
		int index = i;
		for (int j = i+1; j < nums.size();j++) {
			if (nums[j] < min) {
				min = nums[j];
				index = j;
			}
		}
		if (index != i) {
			std::swap(nums[i],nums[index]);
		}
	}
}
int main()
{
	std::vector<int> nums = { 5,8,3,9,1 };
	Sort mysort;
	mysort.SelectionSort(nums);
	for (int i = 0; i < nums.size(); i++) {
		std::cout << nums[i] << " ";
	}
}
