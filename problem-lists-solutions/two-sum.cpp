// problem link: https://leetcode.com/problems/two-sum/

// BRUTE FORCE
// idea: check all possibilities
// time complexity: O(n²)
// space complexity: O(1)
vector<int> twoSum_naive(vector<int> &nums, int target){
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i]+nums[j]==target)
                return {i,j};
        }
    }

    // if no solution is found, return empty array
    return {};
}

// TWO-PASS HASH TABLE
// idea: map each element in the array to its index using a hash table
// reduces the lookup from O(n) to O(1)
// in the first iteration: build the hash table
// in the second iteration: look for complement in hash table
// time complexity: O(n)
// space complexity: O(n)
vector<int> twoSum_hash1(vector<int> &nums, int target){
    unordered_map<int, int> hash;
    for(int i=0; i<nums.size(); i++){
        hash[nums[i]] = i;
    }

    for(int i=0; i<nums.size(); i++){
        int complement = target-nums[i];
        if(hash.find(complement) != hash.end() && hash[complement]!=i){
            return {i, hash[complement]};
        }
    }

    // if no solution is found, return empty array
    return {};
}

// ONE-PASS HASH TABLE
// idea: add to hash table while searching for the pair of numbers
// time complexity: O(n)
// space complexity: O(n)
vector<int> twoSum_hash2(vector<int> &nums, int target){
    unordered_map<int, int> hash;
    for(int i=0; i<nums.size(); i++){
        int complement = target - nums[i];
        if(hash.find(complement)!=hash.end())
            return {hash[complement], i};
        hash[nums[i]] = i;
    }
    // if no solution is found, return empty array
    return {};
}
