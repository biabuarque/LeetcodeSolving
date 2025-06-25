// problem link: https://leetcode.com/problems/3sum-closest/

// BRUTE FORCE
// idea: test all possible triples
// time complexity: O(n³)
// space complexity: O(1)


// TWO POINTERS  WITH SORTING
// idea: sort array, fix an i position and, for each iteration, search for l and r
// pointers to result in sum closer to target as possible
// time complexity: O(n²)
// space complexity: O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
	int numsSize = nums.size();
	int closestResult = nums[0] + nums[1] + nums[2]; // first guess
	// i guesses the first index to compose the resulting sum
	for(int i=0; i<numsSize-2; i++){
		int left = i+1;
		int right = numsSize-1;
		while(left<right){
			int tempSum = nums[i]+nums[left]+nums[right];
			if(abs(tempSum-target)<abs(closestResult-target)){
				closestResult = tempSum;
			}
			if(tempSum == target)
				return target;

			else if(tempSum < target) left++;
			else right--;
		}
	}
	return closestResult;
    }
};
