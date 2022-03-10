#include<iostream>
#include<vector>
void adjustHeap(std::vector<int>& nums,int i, int length) {
	int temp = nums[i];
	for (int k = 2 * i + 1; k < length;k=2*k+1) {
		if (k + 1 < length && nums[k] < nums[k + 1]) {
			k++;
		}
		if (nums[k]>temp) {
			nums[i] = nums[k];
			i = k;
		}
		else {
			break;
		}
		nums[i] = temp;
	}
}
void HeapSort(std::vector<int>& nums) {
	for (int i = nums.size() / 2 - 1; i >= 0;i--) {
		adjustHeap(nums,i,nums.size());
	}
	for (int j=nums.size()-1;j>=0;j--){
		std::swap(nums[0],nums[j]);
		adjustHeap(nums, 0, j);

	}
}
int main() {
	std::vector<int> nums ={ 9,8,7,6,5,4,3,2,1 };
	HeapSort(nums);
	for (int i = 0; i < nums.size();i++) {
		std::cout << nums[i] << " ";
	}
}
