#include <iostream>
#include <vector>
#include <stack>
class Sort{
public:
	void QuickSortIt(std::vector<int>& nums);
private:
	int Partition(std::vector<int>& nums, int left, int right);

};
int Sort:: Partition(std::vector<int>& nums, int left, int right) {
	int l = left;
	int r = right;
	int temp = 0;
	if (l < r) {
		temp = nums[l];
		while (l != r) {
			while (r > l && nums[r] >= temp) r--;
			nums[l] = nums[r];
			while (r > l && nums[l] <= temp) l++;
			nums[r] = nums[l];
		}
		nums[l] = temp;
	}
	return l;
}
void Sort::QuickSortIt(std::vector<int>& nums) {
	std::stack<int> s;
	int left = 0;
	int right = nums.size()-1;
	s.push(left);
	s.push(right);
	while (!s.empty()) {
		int r = s.top();
		s.pop();
		int l = s.top();
		s.pop();                                                                                              		
		int index = Partition(nums,l,r);
		if ((index-1)>l) {
			s.push(l);
			s.push(index - 1);
		}
		if ((index+1)<r) {
			s.push(index + 1);
			s.push(r);
		}
	}
}
int main()
{
	std::vector<int> nums = { 5,8,3,9,1 };
	Sort mysort;
	mysort.QuickSortIt(nums);
	for (int i = 0; i < nums.size(); i++) {
		std::cout << nums[i] << " ";
	}
}

