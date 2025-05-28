// problem link: https://leetcode.com/problems/maximum-subarray/

// GO THROUGH ARRAY
// idea: build sum and compare with current maximum 
// time complexity: O(n)
// space complexity: O(1)

int maxSubArray(vector<int>& nums){
	if(nums.empty())
		return 0;
	int maxSum = nums[0];
	int currSum = nums[0];
	
	for(int i=1; i<nums.size(); i++){
		currSum = max(nums[i], currSum+nums[i]);
		maxSum = max(maxSum, currSum);
	}
	
	return maxSum;
}
