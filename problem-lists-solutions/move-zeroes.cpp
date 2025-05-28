// problem link: https://leetcode.com/problems/move-zeroes/description/

// MEMORY SUB-OPTIMAL
// idea: count zeroes and create another array, ans, to store answer
// time complexity: O(n)
// space complexity: O(n)

void moveZeros1(vector<int> &nums){
	int n = nums.size();
	
	// count zeroes
	int numZeroes = 0;
	for(int i=0; i<n; i++){
		numZeroes += (nums[i]==0);
	}
	
	// put other elements in answer
	vector<int> ans;
	for(int i=0; i<n; i++){
		if(nums[i] != 0)
			ans.push_back(nums[i]);
	}
	
	// add zeroes to the end
	while(numZeroes--){
		ans.push_back(0);
	}
	
	// pass the result to the original vector
	for(int i=0; i<n; i++)
		nums[i] = ans[i];
}


// SPACE OPTIMAL
// idea: two pointers (one for position of the last non zero found
// and another for processing array elements, i.e, nums[i])
// time complexity: O(n)
// space complexity: O(1)

void moveZeroes2(vector<int> &nums){
	int lastNonZeroFoundAt = 0;
	
	for(int i=0; i<nums.size(); i++){
		if(nums[i] != 0){
			nums[lastNonZeroFoundAt++] = nums[i];
		}
	}
	
	for(int i=lastNonZeroFoundAt; i<nums.size(); i++){
		nums[i] = 0;
	}
}


// TOTALLY OPTIMAL
// idea: fast pointer (curr) goes through every element of
// the array, while slow pointer if fixed in last position found
// of a non zero element
// time complexity: O(n) - but it is faster then the previous code, because
// it does not need 2 loop
// space complexity: O(1)

void moveZeroes3(vector<int> &nums){
	for(int lastNonZeroFoundAt = 0, curr=0; curr<nums.size(); curr++){
		if(nums[curr] != 0){
			swap(nums[curr], nums[lastNonZeroFoundAt++]);
		}
	}
}
