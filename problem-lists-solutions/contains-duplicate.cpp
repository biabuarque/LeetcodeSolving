// problem link: https://leetcode.com/problems/contains-duplicate/


// NAIVE
// idea: check for each pair of numbers if they are equal
// time complexity: O(n²)
// space complexity: O(1)

bool containsDuplicate1(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j])
                return true;
        }
    }
    return false;
}

// SORTING
// idea: sort before checking neighbours
// time complexity: O(n log(n))
// space complexity: O(1)

bool containsDuplicate2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int numsSize = nums.size();
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1])
            return true;
    }
    return false;
}

// UNORDERED SET
// idea: store on set, the elements already seen
// time complexity: O(n)
// space complexity: O(n)

bool containsDuplicate3(vector<int>& nums){
		unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num) > 0)
                return true;
            seen.insert(num);
        }
    return false;
}

// UNORDERED MAP (hash table)
// idea: store on map, the count of elements already seen
// time complexity: O(n) - better than the last one
// space complexity: O(n)

bool containsDuplicate4(vector<int>& nums){
    unordered_map<int, int> seen;
    for (int num : nums) {
        if (seen[num] >= 1)
            return true;
        seen[num]++;
    }
    return false;
}
