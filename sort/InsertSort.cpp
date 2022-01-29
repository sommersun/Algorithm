#include <iostream>
#include <vector>
class Sort{
public:
	void InsertSort(std::vector<int>& nums);
};

void Sort::InsertSort(std::vector<int>& nums)
{	//sort from small to big

	for (int i = 1; i < nums.size(); i++) {
		int number = nums[i];
		int j = i - 1;
		while( j >=0&&number < nums[j]) {
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j+1] = number;
	}
}
int main()
{
	std::vector<int> nums = { 5,8,3,9,1 };
	Sort mysort;
	mysort.InsertSort(nums);
	for (int i = 0; i < nums.size(); i++) {
		std::cout << nums[i] << " ";
	}
}
