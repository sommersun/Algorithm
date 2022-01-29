#include <iostream>
#include <vector>
class Sort{
public:
	void QuickSort(std::vector<int>& nums,int left,int right);
};
void Sort::QuickSort(std::vector<int>& nums,int left,int right)
{	
	int l = left;
	int r = right;
	int temp = 0;
	if (l<r) {
		temp = nums[l];
		while (l!=r) {
			while (r > l && nums[r] >= temp) r--;
			nums[l] = nums[r];
			while (r > l && nums[l]<= temp) l++;
			nums[r] = nums[l];
		}
		nums[r] = temp;
		QuickSort(nums,left,l-1);
		QuickSort(nums, r+1, right);
	}

}
int main()
{
	std::vector<int> nums = { 5,8,3,9,1 };
	Sort mysort;
	mysort.QuickSort(nums,0,4);
	for (int i = 0; i < nums.size(); i++) {
		std::cout << nums[i] << " ";
	}
}
