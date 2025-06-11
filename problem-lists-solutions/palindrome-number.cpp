// problem link: https://leetcode.com/problems/palindrome-number/description/

// solution: COMPARE ORIGINAL AND REVERSED 
// idea explanation: store original number and reversed number (build reversed with mod logic)
// time complexity: O(log10(n)) - run through digits of number
// space complexity: O(1) - only extra variables


class Solution {
public:
    bool isPalindrome(int x) {
        // base case 
        if (x<0){
            return false;
        }

        long long reversed = 0;
        long long original = x;

        while(x){
            long long digit = x%10;
            reversed = reversed * 10;

            reversed = reversed + digit;

            x /= 10;
        }

        while (original){
            long long digit1 = original%10;
            long long digit2 = reversed%10;

            if(digit1 != digit2){
                return false;
            }

            original /= 10;
            reversed /=10;
        }

        return true;
    }
};
