// problem link: https://leetcode.com/problems/3sum/description/

// NAIVE SOLUTION
// idea: brute force all possible triples and check condition (use set to store) 
// time complexity: O(n³)
// space complexity: O(unique_triples)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
	vector<vector<int>> ans; 
	set <vector<int>> answers;
	for(int i=0; i<n; i++){
	   for(int j=i+1; j<n; j++){
	   	for(int k=j+1; k<n; k++){
		   if(nums[i]+nums[j]+nums[k]==0){
		   	vector<int> trip = {nums[i], nums[j], nums[k]};
			sort(trip.begin(), trip.end());
			answers.insert(trip);
	           }
		}
	   }
	}
    	for(auto u : answers)
		ans.push_back(u);
    }
};

// BETTER SOLUTION WITH HASHING
// idea: fix x, and do 2-sum to find (z+y)=-x on the array
// time complexity: O(n²*log(unique_triples))
// space complexity: O(unique_triples+n) 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
	vector<vector<int>> ans;
	unordered_set<vector<int>> uniqueTriples;
	for(int i=0; i<n; i++){
		int target = -nums[i];
		unorderedset<int> temp;
		for(int j=i+1; j<n; j++){
			int third = target-nums[j];
			if(temp.find(third) ! temp.end()){
				vector<int> trip = {nums[i], nums[j], third};
				sort(trip.begin(), trip.end());
				uniqueTriples.insert(trip);
			}
			temp.insert(nums[j]);
		}
	}
	vector<vector<int>> ans(uniqueTriples.begin(), uniqueTriples.end());
	return ans;
    }
};

// BEST SOLUTION WITH 2-POINTERS
// idea: sort the array, fix i and move j or k based on the resulting sum
// time complexity: O()
// space complexity: O(unique-triples)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
	vector<vector<int>> ans;
	sort(nums.begin(), nums.end());
	for(i=0; i<n; i++){
		if(int i>0 && nums[i]==nums[i-1]) continue;
		int j= i+1;
		int k = n-1;
		while(j<k){
			int sum = nums[i]+nums[j]+nums[k];
			if(sum<0) j++;
			else if(sum>0) k--;
			else{
				ans.push_back({nums[i], nums[j], nums[k]});
				j++; k--;
				while(j<k && nums[j]==nums[j-1]) j++;
			}
		}
	}
	return ans;
    }
};
