#include <iostream>
#include <vector>
class Sort {
private:
	int Partition(std::vector<int>& nums,int left,int right);
public:
	void QuickSort(std::vector<int>& nums, int left, int right);
};
int Sort::Partition(std::vector<int>& nums,int left,int right) {
	int temp = nums[left];
	while (left < right) {
		while (right > left && nums[right] >= temp) right--;
		nums[left] = nums[right];
		while (right > left && nums[left] <= temp) left++;
		nums[right] = nums[left];
	}
	nums[left] = temp;
	return left;
}
void Sort::QuickSort(std::vector<int>& nums, int left, int right)
{
	if (left >= right) {
		return;
	}
	int pivot = Partition(nums, left, right);
	QuickSort(nums, left, pivot-1);
	QuickSort(nums, pivot+1, right);

}
int main()
{
	std::vector<int> nums = { 5,8,3,9,1 };
	Sort mysort;
	mysort.QuickSort(nums, 0, 4);
	for (int i = 0; i < nums.size(); i++) {
		std::cout << nums[i] << " ";
	}
}
