// problem link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// BACKTRACKING
// idea: build all possible combinations using backtracking technique
// time complexity: O(4^n)
// space complexity: O(4^n * n)

class Solution {
public:

    void backtrackSolution(vector<string>& res, string next_digits, string currCombination, map<char, string>& phone_map){
	// base case (built a combination using all digits)
	if(next_digits.size()==0){
		res.push_back(currCombination);
		return;
	}
	for(auto letter : phone_map[next_digits[0]]){
		backtrackSolution(res, next_digits.substr(1), currCombination+letter, phone_map);
	}
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
	if (digits.size() == 0) return res;
	map <char, string> phone_map;
	phone_map['2'] = "abc";
	phone_map['3'] = "def";
	phone_map['4'] = "ghi";
	phone_map['5'] = "jkl";
	phone_map['6'] = "mno";
	phone_map['7'] = "pqrs";
	phone_map['8'] = "tuv";
	phone_map['9'] = "wxyz";
	
	backtrackSolution(res, digits, "", phone_map);
	return res;
    }
};
