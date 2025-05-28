// prblem link: https://leetcode.com/problems/rotate-array/


// MEMORY SUB-OPTIMAL
// idea: use another array to store answer
// time complexity: O(n)
// space complexity: O(n)
void rotate1(vector<int>& nums, int k){
	int numsSize = (int) nums.size();
	vector<int> ans (n);
	
	for(int i=0; i<numsSize; i++){
		int index = (i+k)%numsSize;
		ans[index] = nums[i];
	}
	
	for(int i=0; i<numsSize; i++){
		nums[i] = ans[i];
	}
}

// MEMORY OPTIMAL
// idea: use array index logic in our favor
// time complexity: O(n)
// space complexity: O(1)
void rotate2(vector<int>& nums, int k) {
  int n = (int) nums.size();
  int m = k%n;
  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin()+m);
  reverse(nums.begin()+m, nums.end());
}
