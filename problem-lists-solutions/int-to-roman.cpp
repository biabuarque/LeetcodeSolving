// problem link: https://leetcode.com/problems/integer-to-roman/

// CONSTRUCT WHILE PROCESSING NUMBER
// idea: map numbers to roman symbol and construct the answer decrementing from number
// time complexity: O(n)
// space complexity: O(roman_string.size())

class Solution {
public:
    string intToRoman(int num) {
	int numbers[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i =0;
        string ans = ""; 
        while (num>0){
            if (num>=numbers[i]){
                ans=ans+roman[i];
                num-=numbers[i];
            } else{
                i++;
            }
        }
        return ans;
    }
};

// FASTER SOLUTION WITH MATH
// idea: since the number is at most 3999, we can create an array of strings for corresp in 1000s, 100s, 10s and 1s
// and calculate the corresp roman string for each multiple of 10
// time complexity: O(1)
// space complexity: O(roman-strings)

class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};

