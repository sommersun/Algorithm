#include <iostream>
#include <vector>
#include <stack>
class Sort{
public:
	void bubbleSort(std::vector<int>& nums);
	void SelectionSort(std::vector<int>& nums);
	void InsertSort(std::vector<int>& nums);
	void QuickSort(std::vector<int>& nums,int left,int right);
	void QuickSortIt(std::vector<int>& nums);
	void MergeSort(std::vector<int>& nums,int left,int right);
private:
	int Partition(std::vector<int>& nums, int left, int right);
	void Merge(std::vector<int>& nums, int left, int mid, int right);

};

void Sort::bubbleSort(std::vector<int>& nums) {
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
		nums[r] = temp;
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
void Sort::MergeSort(std::vector<int>& nums,int left,int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(nums, left, mid);
		MergeSort(nums, mid + 1, right);
		Merge(nums, left, mid, right);
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

